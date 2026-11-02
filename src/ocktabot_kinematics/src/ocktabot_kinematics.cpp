//Implementation of ocktabot_kinematics::OcktabotKinematics (declared in ocktabot_kinematics.hpp)

#include "ocktabot_kinematics/ocktabot_kinematics.hpp"

#include <algorithm>
#include <cstdint>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>

namespace{
    const std::vector<std::string> kDefaultMotorNames = {"motor1", "motor2", "motor3"};
    const std::vector<bool> kDefaultIkSpec = {true, true, true, false, false, false}; //x, y, z
    constexpr double kDefaultMaxJumpDeg = 15.0;
    constexpr int kWarnPeriodMs = 1000;
    //epos2_gateway reports 0 rad with the links straight up (full extension),
    //which is phi_in = 90 deg in the kinematics
    constexpr double kLinksUp = stewart::PI / 2.0;

//every per-motor parameter needs exactly one value per motor
void checkSize(const std::string& name, std::size_t size){
    if (size != 3) throw std::invalid_argument("parameter " + name + " needs exactly 3 values");
}

} //namespace

namespace ocktabot_kinematics{

OcktabotKinematics::OcktabotKinematics() : Node("ocktabot_kinematics"), sim_(stewart::defaultGeometry()){

    using namespace std::placeholders;

    motor_names_ = declare_parameter<std::vector<std::string>>("motor_names", kDefaultMotorNames);
    motor_scale_ = declare_parameter<std::vector<double>>("motor_scale", {1.0, 1.0, 1.0});
    motor_offset_ = declare_parameter<std::vector<double>>("motor_offset", {kLinksUp, kLinksUp, kLinksUp});
    const auto ikSpec = declare_parameter<std::vector<bool>>("ik_spec", kDefaultIkSpec);
    const auto topAssembly = declare_parameter<int64_t>("top_assembly", 1);
    const auto maxJumpDeg = declare_parameter<double>("max_jump_deg", kDefaultMaxJumpDeg);
    frame_id_ = declare_parameter<std::string>("frame_id", "base");

    checkSize("motor_names", motor_names_.size());
    checkSize("motor_scale", motor_scale_.size());
    checkSize("motor_offset", motor_offset_.size());
    if (std::any_of(motor_scale_.begin(), motor_scale_.end(), [](double s){return s == 0.0;})) {
        throw std::invalid_argument("parameter motor_scale must not contain 0");
    }
    if (ikSpec.size() != 6 || std::count(ikSpec.begin(), ikSpec.end(), true) != 3) {
        throw std::invalid_argument("parameter ik_spec needs 6 values (x, y, z, roll, pitch, yaw), exactly 3 true");
    }
    std::copy(ikSpec.begin(), ikSpec.end(), ik_spec_.begin());

    stewart::Geometry geometry = stewart::defaultGeometry();
    geometry.topAssembly = static_cast<int>(topAssembly);
    sim_ = stewart::Simulation(geometry, maxJumpDeg * stewart::DEG);

    //both callbacks use sim_; the default single-threaded executor never runs them at the same time
    motor_jointstate_subscriber_ = create_subscription<sensor_msgs::msg::JointState>("motor_jointstate", 10,
        [this](const sensor_msgs::msg::JointState::SharedPtr msg){onMotorJointState(msg);});

    endeffector_pos_publisher_ = create_publisher<geometry_msgs::msg::PoseStamped>("endeffector_pos", 10);

    get_jointpos_ik_service_ = create_service<ocktabot_interfaces::srv::GetJointPosIK>("get_jointpos_ik",
        std::bind(&OcktabotKinematics::getJointPosIK, this, _1, _2));
}

bool OcktabotKinematics::readMotorAngles(const sensor_msgs::msg::JointState& msg, stewart::Vec3& phi,
    std::string& reason) const{
    for (int j = 0; j < 3; ++j){
        std::size_t i = static_cast<std::size_t>(j);
        //without names the positions are taken in order
        if (!msg.name.empty()){
            const auto it = std::find(msg.name.begin(), msg.name.end(), motor_names_[j]);
            if (it == msg.name.end()){
                reason = "no joint named " + motor_names_[j];
                return false;
            }
            i = static_cast<std::size_t>(std::distance(msg.name.begin(), it));
        }
        if (i >= msg.position.size()){
            reason = "no position for " + motor_names_[j];
            return false;
        }
        phi[j] = motor_scale_[j] * msg.position[i] + motor_offset_[j];
    }
    return true;
}

void OcktabotKinematics::onMotorJointState(const sensor_msgs::msg::JointState::SharedPtr msg){
    stewart::Vec3 phi;
    std::string reason;
    if (!readMotorAngles(*msg, phi, reason)){
        RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), kWarnPeriodMs,
            "Ignoring motor_jointstate: %s", reason.c_str());
        return;
    }

    //forward kinematics; if the solution would jump to another configuration
    //(or cannot be assembled) the previous pose is held and published again
    const stewart::FKUpdate fk = sim_.update(stewart::Config{phi});
    if (fk.held){
        RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), kWarnPeriodMs,
            "Holding the previous end effector pose: %s", fk.reason.c_str());
    }
    if (!fk.valid) return;

    geometry_msgs::msg::PoseStamped message;
    message.header.stamp = msg->header.stamp;
    if (rclcpp::Time(message.header.stamp).nanoseconds() == 0) message.header.stamp = now();
    message.header.frame_id = frame_id_;
    message.pose.position.x = fk.pose[0];
    message.pose.position.y = fk.pose[1];
    message.pose.position.z = fk.pose[2];
    const Eigen::Quaterniond q(fk.Q);
    message.pose.orientation.x = q.x();
    message.pose.orientation.y = q.y();
    message.pose.orientation.z = q.z();
    message.pose.orientation.w = q.w();
    endeffector_pos_publisher_->publish(message);

    RCLCPP_DEBUG(get_logger(), "end effector x %.4f y %.4f z %.4f roll %.2f pitch %.2f yaw %.2f deg",
        fk.pose[0], fk.pose[1], fk.pose[2],
        stewart::rad2deg(fk.pose[3]), stewart::rad2deg(fk.pose[4]), stewart::rad2deg(fk.pose[5]));
}

void OcktabotKinematics::getJointPosIK(const std::shared_ptr<ocktabot_interfaces::srv::GetJointPosIK::Request> request,
    std::shared_ptr<ocktabot_interfaces::srv::GetJointPosIK::Response> response){
    stewart::Vec6 target;
    for (int i = 0; i < 6; ++i) target[i] = request->target[i];

    const stewart::IKUpdate ik = sim_.inverse(target, ik_spec_);
    response->name = motor_names_;
    if (!ik.ok){
        response->success = false;
        response->message = ik.reason;
        response->motor_positions.fill(std::numeric_limits<double>::quiet_NaN());
        response->pose.fill(std::numeric_limits<double>::quiet_NaN());
        RCLCPP_WARN(get_logger(), "get_jointpos_ik failed: %s", ik.reason.c_str());
        return;
    }

    //base link angle -> motor units (inverse of readMotorAngles)
    for (int j = 0; j < 3; ++j){
        response->motor_positions[j] = (ik.motorPos[j] - motor_offset_[j]) / motor_scale_[j];
    }
    for (int i = 0; i < 6; ++i) response->pose[i] = ik.pose[i];
    response->success = true;
    response->message = "IK solved";
}

} //namespace ocktabot_kinematics

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  int exitCode = 0;
  try {
    auto node = std::make_shared<ocktabot_kinematics::OcktabotKinematics>();
    rclcpp::spin(node);
  } catch(const std::exception & e){
    std::cerr << "Error: " << e.what() << std::endl;
    exitCode = 1;
  }
  rclcpp::shutdown();
  return exitCode;
}

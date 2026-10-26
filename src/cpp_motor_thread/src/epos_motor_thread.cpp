#include <chrono>
#include <memory>
#include <string>
#include <atomic>
#include <csignal>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <thread>

#include "Definitions.h"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using namespace std::chrono_literals;


namespace {

constexpr unsigned short kNodes[] = {1};
constexpr unsigned int kProfileVelocity = 500;
constexpr unsigned int kProfileAccel = 500;
constexpr unsigned int kProfileDecel = 500;
constexpr auto kMoveTimeout = std::chrono::milliseconds(10000);
constexpr auto kPollPeriod = std::chrono::milliseconds(10);

std::atomic<bool> g_stopRequested{false};
void onSignal(int) {g_stopRequested = true;};

std::string errorText(unsigned int code) {
  char info[256] = {};
  VCS_GetErrorInfo(code, info, static_cast<unsigned short> (sizeof(info)));
  char hex[16];
  std::snprintf(hex, sizeof(hex), "0x%08X", code);
  return std::string(hex) + info;  
}

void check(int ok, unsigned int errorCode, const std::string& what){
  if (!ok) throw std::runtime_error(what + "failed: " + errorText(errorCode));
}

std::string nodeLabel(const char* action, unsigned short node) {
  return std::string(action) + "node" + std::to_string(node);
}

class Epos2Gateway : public rclcpp::Node
{
public:
//make a header file
  int position(unsigned short node){
    int pos = 0;
    unsigned int err = 0;
    check(VCS_GetPositionIs(handle_, node, &pos, &err), err, nodeLabel("GetPositionIs", node));
    return pos;
  }
  Epos2Gateway()
  : Node("epos2_gateway"), count_(0)
  {
    char device[] = "EPOS2";
    char protocol[] = "MAXON SERIAL V2";
    char interface[] = "USB";
    char port[] = "USB0";
    unsigned int err = 0;
    handle_ = VCS_OpenDevice(device, protocol, interface, port, &err);
    if(!handle_) {
      throw std::runtime_error("OpenDevice failed (USB permissions or ftdi_sio conflict?): " + errorText(err));
    }

    // publisher
    node1_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("node1_jointstate", 10);
    auto timer_callback =
    [this]() -> void {
      auto message = sensor_msgs::msg::JointState();
      for (auto node : kNodes) {
        message.position.push_back(this->position(node));
        RCLCPP_INFO(this->get_logger(), "Publishing: node 1, position '%.4f'", message.position.back());//message.name.c_str(), message.position);
      }
      this->node1_publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(100ms, timer_callback);
  }
  ~Epos2Gateway() {
    unsigned int err = 0;
    for (auto node : kNodes) VCS_SetDisableState(handle_, node, &err);
    VCS_CloseDevice(handle_, &err);
    std::cout << "Drives disable, device closed";
  }

  Epos2Gateway(const Epos2Gateway&) = delete;
  Epos2Gateway& operator=(const Epos2Gateway&) = delete;

  bool inFault(unsigned short node){
    int fault = 0;
    unsigned int err = 0;
    check(VCS_GetFaultState(handle_, node, &fault, &err), err, nodeLabel("GetFaultState", node));
    return fault != 0;
  }

  void prepareProfilePosition(unsigned short node) {
    unsigned int err = 0;
    check(VCS_ClearFault(handle_, node, &err), err, nodeLabel("ClearFault", node));
    check(VCS_SetEnableState(handle_, node, &err), err, nodeLabel("SetEnableState", node));
    check(VCS_ActivateProfilePositionMode(handle_, node, &err), err, nodeLabel("ActivateProfilePositionMode", node));
    check(VCS_SetPositionProfile(handle_, node, kProfileVelocity, kProfileAccel, kProfileDecel, &err), err, nodeLabel("SetProfilePosition", node));
  }


private:
  void* handle_ = nullptr;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr node1_publisher_;
  size_t count_;
};
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Epos2Gateway>());
  rclcpp::shutdown();
  return 0;
}
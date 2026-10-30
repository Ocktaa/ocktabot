


namespace {
}

namespace ocktabot_kinematics {

OcktabotKinematics::OcktabotKinematics() : Node("ocktabot_kinematics"){}
OcktabotKinematics::~OcktabotKinematics(){}

glm::vec3 OcktabotKinematics::wVec(double beta, double phi){
    return {cos(beta)*cos(phi), sin(beta)*sin(phi), sin(phi)};
}

glm::vec3 OcktabotKinematics::dwvec(double beta, double phi){
    return {-cos(beta)*sin(phi); -sin(beta)*sin(phi); cos(phi)}
}
}
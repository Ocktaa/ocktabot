#ifndef OCKTABOT_KINEMATICS__OCKTABOT_KINEMATICS_HPP
#define OCKTABOT_KINEMATICS__OCKTABOT_KINEMATICS_HPP

#include "rclcpp/rclcpp.hpp"
#include <glm/glm.hpp>
namespace ocktabot_kinematics {

class OcktabotKinematics: public rclcpp::Node
public:

    OcktabotKinematics();
    ~OcktabotKinematics();

    void getEndEffectorPosition(); //Forward Kinematics
    void getMotorJointPosition(); // Inverse Kinematics

    //define the position of one stage
    struct Stage { 
        glm::vec3 O[2];          //hinge corners R,S,T
        double m[2];        //link lengths
        double beta[2];     //swing diretion of each link in the plate plane [rad]
        glm::vec3 u[2];          // hinge axes (drawwing + checks only)
    };

    struct stageSolution{

    };

    struct System{

    }:



private:
    //stacked Forward Kinematics
    double[] stageFromPoints();
    void solveStage():
    void fkChain();
    void legCheckStage();

    //stacked IK
    void ikLayout();
    void seedFromChain();
    void seedFromframe();
    void ikEqsN();
    void solveIKN();
    void trackIKN();

    //Stage Geometry Definition
    void stageGeometry();
    void fitRigit();

    //pose Helpers
    void poseVector();
    void rotZYX();
    void dwvec();

    void baseGeometry();
    void legPairs();
    void equivalentArms();
    void wvec();
    void jointPositions();
    void pairCoeffs();
    void HalfAngle();
    void resultantPoly();
    void resultandAt();
    void stewardDK();
    void polishPhi();
    void phiEqs();
    void trigEq();
    void sortByHeight();
    void angWrapper();




}
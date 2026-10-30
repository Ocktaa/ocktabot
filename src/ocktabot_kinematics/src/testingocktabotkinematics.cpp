#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <glm/gtx/string_cast.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
glm::vec2 calculateCentroid(const std::vector<glm::vec2>& vertices) {
    if (vertices.empty()) {
        return glm::vec2(0.0f);
    }

    glm::vec2 sum(0.0f);
    for (const auto& v : vertices) {
        sum += v;
    }

    return sum / static_cast<float>(vertices.size());
}

glm::vec3 wVec(double beta, double phi){
    return {cos(beta)*cos(phi), sin(beta)*sin(phi), sin(phi)};
}

double angWrap(double a){
    double TWO_PI = 2.0*M_PI;
    return a - TWO_PI * std::floor((a + M_PI) / TWO_PI);
}
int main(){
    //glm::vec3 w = wVec(2,2);
    double angle = 3.31613;
    double radians = angWrap(angle);
    
    std::cout<<std::to_string(radians)<<std::endl;

    return 0;
}
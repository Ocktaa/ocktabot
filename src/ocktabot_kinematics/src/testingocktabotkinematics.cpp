#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <glm/gtx/string_cast.hpp>

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

int main(){
    std::vector<glm::vec2> tri_corners = {{-2,0}, {2,0}, {0,2}};
    float area2;
    std::vector<float> beta;
    std::vector<double> u;
    int mean;
    //area2 = (glm::length(cross(tri_corners[1]-tri_corners[0],tri_corners[2]-tri_corners[1])));
    glm::vec2 centroid = calculateCentroid(tri_corners);
    //std::cout << glm::to_string(centroid) << std::endl;
    glm::vec2 angle = glm::atan(tri_corners[2]);
    for (glm::vec2 point : tri_corners){
        //beta.push_back(glm::atan(centroid - point));
        //std::cout << glm::to_string(glm::atan(centroid - point)) << std::endl; 
    }
    std::cout << glm::to_string(angle) << std::endl;

    return 0;
}
#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float2.hpp"

class Camera {
public:
    Camera();
    Camera(glm::vec2 const & position);
    glm::mat4 viewMatrix();
    glm::vec2 position;
};

#include "camera.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"

glm::mat4 Camera::viewMatrix()
{
    glm::vec3 eye = glm::vec3(position, 1);
    glm::vec3 center = glm::vec3(position, 0);
    return glm::lookAt(eye, center, glm::vec3(0, 1, 0));
}

Camera::Camera()
{}

Camera::Camera(glm::vec2 const &position) :
    position(position)
{

}

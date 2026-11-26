#include "camera.ih"

glm::mat4 Camera::viewMatrix()
{
    glm::vec3 eye = glm::vec3(position, 1);
    glm::vec3 center = glm::vec3(position, 0);
    glm::vec3 lookUp = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0, 0, 1)) * glm::vec4(0, 1, 0, 0);
    return glm::lookAt(eye, center, lookUp);
}

Camera::Camera()
{}

Camera::Camera(glm::vec2 const &position) :
    position(position)
{

}

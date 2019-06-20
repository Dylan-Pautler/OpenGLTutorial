//
// Created by dylan on 6/20/19.
//

#ifndef OPENGLTUTORIALPROJECT_CAMERA_H
#define OPENGLTUTORIALPROJECT_CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL


#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
    Camera(float fov, float aspect, float zNear, float zFar,
           const glm::vec3 &pos = glm::vec3(0, 0, -3),
           const glm::vec3 &forward = glm::vec3(0, 0, 1),
           const glm::vec3 &up = glm::vec3(0, 1, 0))
    {
        _m_perspective = glm::perspective(fov, aspect, zNear, zFar);
        _m_position = pos;
        _m_forward = forward;
        _m_up = up;
    }

    inline glm::mat4 GetViewProjection() const
    {
        return _m_perspective * glm::lookAt(_m_position, _m_position + _m_forward, _m_up);
    }

    // make getters and setters if necessary

private:
    glm::mat4 _m_perspective;
    glm::vec3 _m_position;
    glm::vec3 _m_forward;
    glm::vec3 _m_up;
};


#endif //OPENGLTUTORIALPROJECT_CAMERA_H

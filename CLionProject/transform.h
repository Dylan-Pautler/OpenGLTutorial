//
// Created by dylan on 6/20/19.
//

#ifndef OPENGLTUTORIALPROJECT_TRANSFORM_H
#define OPENGLTUTORIALPROJECT_TRANSFORM_H
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
    Transform(const glm::vec3 &pos = glm::vec3(),
              const glm::vec3 &rot = glm::vec3(),
              const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
            _m_pos(pos), _m_rot(rot), _m_scale(scale)
    {}

    inline glm::mat4 GetModel() const
    {
        glm::mat4 posMatrix = glm::translate(_m_pos);
        glm::mat4 rotXMatrix = glm::rotate(_m_rot.x, glm::vec3(1,0,0));
        glm::mat4 rotYMatrix = glm::rotate(_m_rot.y, glm::vec3(0,1,0));
        glm::mat4 rotZMatrix = glm::rotate(_m_rot.z, glm::vec3(0,0,1));
        glm::mat4 scaleMatrix = glm::scale(_m_scale);

        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        return posMatrix * rotMatrix * scaleMatrix;
    }

    inline glm::vec3 &GetPos() {return _m_pos;}
    inline glm::vec3 &GetRot() {return _m_rot;}
    inline glm::vec3 &GetScale() {return _m_scale;}

    inline void SetPos(const glm::vec3 &pos) {_m_pos = pos;}
    inline void SetRot(const glm::vec3 &rot) {_m_rot = rot;}
    inline void SetScale(const glm::vec3 &scale) {_m_scale = scale;}


    ~Transform()
    {

    }

private:
    glm::vec3 _m_pos;
    glm::vec3 _m_rot;
    glm::vec3 _m_scale;
};


#endif //OPENGLTUTORIALPROJECT_TRANSFORM_H

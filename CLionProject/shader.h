//
// Created by dylan on 6/5/19.
//

#ifndef OPENGLTUTORIALPROJECT_SHADER_H
#define OPENGLTUTORIALPROJECT_SHADER_H

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
public:
    Shader(const std::string& fileName);

    void Bind();
    void Update(const Transform &transform, const Camera &camera);

    virtual ~Shader();

private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other){}
    void operator=(const Shader& other){}

    enum
    {
        TRANSFORM_U,

        NUM_UNIFORMS
    };

    GLuint _m_program;
    GLuint _m_shaders[NUM_SHADERS];
    GLuint _m_uniforms[NUM_UNIFORMS];
};

#endif // OPENGLTUTORIALPROJECT_SHADER_H

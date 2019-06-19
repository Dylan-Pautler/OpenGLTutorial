//
// Created by dylan on 6/5/19.
//

#ifndef OPENGLTUTORIALPROJECT_SHADER_H
#define OPENGLTUTORIALPROJECT_SHADER_H

#include <string>
#include <GL/glew.h>
class Shader
{
public:
    Shader(const std::string& fileName);

    void Bind();

    virtual ~Shader();

private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other){}
    void operator=(const Shader& other){}

    GLuint _m_program;
    GLuint _m_shaders[NUM_SHADERS];
};

#endif // OPENGLTUTORIALPROJECT_SHADER_H

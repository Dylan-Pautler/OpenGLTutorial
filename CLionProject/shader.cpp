//
// Created by dylan on 6/5/19.
//

#include "shader.h"
#include <iostream>
#include <fstream>

static std::string LoadShader(const std::string& fileName);
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName)
{
  _m_program = glCreateProgram();
  _m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
  _m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

  for (unsigned int i = 0; i < NUM_SHADERS; ++i)
    glAttachShader(_m_program, _m_shaders[i]);

  glBindAttribLocation(_m_program, 0, "position");
  glBindAttribLocation(_m_program, 1, "texCoord");
  glBindAttribLocation(_m_program, 2, "normal");

  glLinkProgram(_m_program);
  CheckShaderError(_m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

  // validates if this is a proper program
  glValidateProgram(_m_program);
  CheckShaderError(_m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

  _m_uniforms[TRANSFORM_U] = glGetUniformLocation(_m_program, "transform");
}

Shader::~Shader()
{
  for (unsigned int i = 0; i < NUM_SHADERS; ++i)
  {
    glDetachShader(_m_program, _m_shaders[i]);
    glDeleteShader(_m_shaders[i]);
  }

  glDeleteProgram(_m_program);
}

void Shader::Bind()
{
  glUseProgram(_m_program);
}

void Shader::Update(const Transform &transform, const Camera &camera)
{
    // cheap because only needs to send one matrix to the GPU
    glm::mat4 model = camera.GetViewProjection() * transform.GetModel();

    //4x4 matrix of float values
    glUniformMatrix4fv(_m_uniforms[TRANSFORM_U], 1 , GL_FALSE, &model[0][0]);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
  GLuint shader = glCreateShader(shaderType);

  if(shader == 0)
    std::cerr << "Error: Shader creation failed!" << std::endl;

  const GLchar* shaderSourceStrings[1];
  GLint shaderSourceStringLengths[1];

  shaderSourceStrings[0] = text.c_str();
  shaderSourceStringLengths[0] = text.length();

  glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
  glCompileShader(shader);

  CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

  return shader;
}

static std::string LoadShader(const std::string& fileName)
{
  std::ifstream file;
  file.open((fileName).c_str());

  std::string output;
  std::string line;

  if(file.is_open())
  {
    while(file.good())
    {
      getline(file, line);
      output.append(line + "\n");
    }
  }
  else
  {
    std::cerr << "Unable to load shader: " << fileName << std::endl;
  }

  return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
  GLint success = 0;
  GLchar error[1024] = {0};

  if (isProgram)
    glGetProgramiv(shader, flag, &success);
  else
    glGetShaderiv(shader, flag, &success);

  if (success == GL_FALSE)
  {
    if(isProgram)
      glGetProgramInfoLog(shader, sizeof(error), nullptr, error);
    else
      glGetShaderInfoLog(shader, sizeof(error), nullptr, error);

    std::cerr << errorMessage << ": '" << error << "'" << std::endl;
  }
}
//
// Created by dylan on 6/4/19.
//

#include "display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
  SDL_Init(SDL_INIT_EVERYTHING);

  // 8 is the MINIMUM amount of bits we could get of any color
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  _m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
  _m_glContext = SDL_GL_CreateContext(_m_window);

  // finds all opengl functions we support
  GLenum status = glewInit();

  if(status != GLEW_OK)
    std::cerr << "Glew failed to initialize!" << std::endl;

  _m_isClosed = false;

}

Display::~Display()
{
  SDL_GL_DeleteContext(_m_glContext);
  SDL_DestroyWindow(_m_window);
  SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}


bool Display::IsClosed()
{
  return _m_isClosed;
}

void Display::Update()
{
  // since double buffer is 2 mem chunks, this swaps the drawn window by opengl
  // with the empty buffer being pointed at by the actual window
  // https://www.youtube.com/watch?v=DkiKgQRiMRU&list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh&index=5 TS: 1659
  // ** point is that the actual window never displays something in the act of being drawn **
  SDL_GL_SwapWindow(_m_window);

  SDL_Event e;

  while(SDL_PollEvent(&e))
  {
    if(e.type == SDL_QUIT)
      _m_isClosed = true;
  }
}

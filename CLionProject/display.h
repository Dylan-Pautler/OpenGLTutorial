//
// Created by dylan on 6/4/19.
//

#ifndef OPENGLTUTORIALPROJECT_DISPLAY_H
#define OPENGLTUTORIALPROJECT_DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class Display {
public:
    Display(int width, int height, const std::string& title);

    void Clear(float r, float g, float b, float a);
    void Update();
    bool IsClosed();

    virtual ~Display();

private:
    Display(const Display &other){}
    void operator=(const Display& other){}

    SDL_Window* _m_window;
    SDL_GLContext  _m_glContext;
    bool _m_isClosed;
};


#endif //OPENGLTUTORIALPROJECT_DISPLAY_H

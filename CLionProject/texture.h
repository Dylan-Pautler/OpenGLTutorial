//
// Created by dylan on 6/19/19.
//

#ifndef OPENGLTUTORIALPROJECT_TEXTURE_H
#define OPENGLTUTORIALPROJECT_TEXTURE_H

#include <string>
#include <GL/glew.h>


class Texture
{
public:
    Texture(const std::string &fileName);

    // can have multiple textures at once (max is 32). used to distinguish between textures
    void Bind(unsigned int unit);

   virtual ~Texture();

private:
    GLuint _m_texture;
};


#endif //OPENGLTUTORIALPROJECT_TEXTURE_H

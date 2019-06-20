//
// Created by dylan on 6/19/19.
//

#include "texture.h"
#include "stb_image.h"
#include <string>
#include <cassert>
#include <iostream>


Texture::Texture(const std::string &fileName)
{
    int width, height, numComponents;
    unsigned char* imageData = stbi_load((fileName).c_str(), &width, &height, &numComponents, 4);

    if( !imageData)
        std::cerr << "Texture loading failed for texture : " << fileName << std::endl;

    glGenTextures(1, &_m_texture);
    glBindTexture(GL_TEXTURE_2D, _m_texture);

    //glTexImage2D();

    // texture wrap s/t read out the texture width and height, repeat sends the pixel counter back to zero
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // min filter is for when texture takes up less pixels that the entire size (linearly interpolation)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // mag is opposite, play with gl linear for interesting effects
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

Texture::~Texture()
{
    glDeleteTextures(1, &_m_texture);
}

void Texture::Bind(unsigned int unit)
{
    assert(unit >= 0 && unit < 32);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, _m_texture);
}

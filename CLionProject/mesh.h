//
// Created by dylan on 6/7/19.
//

#ifndef OPENGLTUTORIALPROJECT_MESH_H
#define OPENGLTUTORIALPROJECT_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2 &texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }

    inline glm::vec3 *GetPos() { return &pos; }
    inline glm::vec2 *GetTexCoord() { return &texCoord; }
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices);

    void Draw();

    virtual ~Mesh();

private:
    Mesh(const Mesh& other);
    void operator=(const Mesh& other);

    enum
    {
        POSITION_VB,
        TEXCOORD_VB,

        NUM_BUFFERS
    };

    GLuint _m_vertexArrayObject;
    GLuint _m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int _m_drawCount;
};



#endif //OPENGLTUTORIALPROJECT_MESH_H

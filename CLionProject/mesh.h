//
// Created by dylan on 6/7/19.
//

#ifndef OPENGLTUTORIALPROJECT_MESH_H
#define OPENGLTUTORIALPROJECT_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2 &texCoord, const glm::vec3 &normal = glm::vec3(0,0,0))
    {
        this->pos = pos;
        this->texCoord = texCoord;
        this->normal = normal;
    }

    inline glm::vec3 *GetPos() { return &pos; }
    inline glm::vec2 *GetTexCoord() { return &texCoord; }
    inline glm::vec3 *GetNormal() { return &normal; }
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
    glm::vec3 normal;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices);
    Mesh(const std::string &fileName);
    void Draw();

    virtual ~Mesh();

private:
    Mesh(const Mesh& other);
    void operator=(const Mesh& other);

    void InitMesh(const IndexedModel &model);

    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
        NORMAL_VB,

        INDEX_VB,

        NUM_BUFFERS
    };

    GLuint _m_vertexArrayObject;
    GLuint _m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int _m_drawCount;
};



#endif //OPENGLTUTORIALPROJECT_MESH_H

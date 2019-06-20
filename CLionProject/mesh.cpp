//
// Created by dylan on 6/7/19.
//

#include "mesh.h"
#include <vector>

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    _m_drawCount = numVertices;

    glGenVertexArrays(1, &_m_vertexArrayObject);
    glBindVertexArray(_m_vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for (unsigned int i = 0; i < numVertices; ++i)
    {
        positions.push_back(*vertices[i].GetPos());
        texCoords.push_back(*vertices[i].GetTexCoord());
    }

    glGenBuffers(NUM_BUFFERS, _m_vertexArrayBuffers);
    // array that holds vertex data
    glBindBuffer(GL_ARRAY_BUFFER, _m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    // vertex attribute is any private vector data
    // if you have multiple vectors in a class, it stores the data in order of the first vector's data
    // of every instance, then skips an element, then continues with the next vertex of each instance
    glEnableVertexAttribArray(0);
    // this figures out how to read your attribarray
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, _m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
    // vertex attribute is any private vector data
    // if you have multiple vectors in a class, it stores the data in order of the first vector's data
    // of every instance, then skips an element, then continues with the next vertex of each instance
    glEnableVertexAttribArray(1);
    // this figures out how to read your attribarray
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &_m_vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(_m_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0,_m_drawCount);

    glBindVertexArray(0);
}
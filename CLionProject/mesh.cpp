//
// Created by dylan on 6/7/19.
//

#include "mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    _m_drawCount = numVertices;

    glGenVertexArrays(1, &_m_vertexArrayObject);
    glBindVertexArray(_m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, _m_vertexArrayBuffers);
    // array that holds vertex data
    glBindBuffer(GL_ARRAY_BUFFER, _m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    // vertex attribute is any private vector data
    // if you have multiple vectors in a class, it stores the data in order of the first vector's data
    // of every instance, then skips an element, then continues with the next vertex of each instance
    glEnableVertexAttribArray(0);
    // this figures out how to read your attribarray
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

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
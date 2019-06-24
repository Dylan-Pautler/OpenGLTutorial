//
// Created by dylan on 6/7/19.
//

#include "mesh.h"
#include "obj_loader.h"
#include <vector>

Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices)
{
    IndexedModel model;

    for (unsigned int i = 0; i < numVertices; ++i)
    {
        model.positions.push_back(*vertices[i].GetPos());
        model.texCoords.push_back(*vertices[i].GetTexCoord());
        model.normals.push_back(*vertices[i].GetNormal());
    }

    for(unsigned int i = 0; i < numIndices; ++i)
        model.indices.push_back(indices[i]);

    InitMesh(model);

}

Mesh::Mesh(const std::string &fileName)
{
    IndexedModel model = OBJModel(fileName).ToIndexedModel();
    InitMesh(model);
}


Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &_m_vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(_m_vertexArrayObject);

    //glDrawArrays(GL_TRIANGLES, 0,_m_drawCount);
    glDrawElements(GL_TRIANGLES, _m_drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void Mesh::InitMesh(const IndexedModel &model)
{
    _m_drawCount = model.indices.size();


    glGenBuffers(NUM_BUFFERS, _m_vertexArrayBuffers);
    // array that holds vertex data
    glBindBuffer(GL_ARRAY_BUFFER, _m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);
    // vertex attribute is any private vector data
    // if you have multiple vectors in a class, it stores the data in order of the first vector's data
    // of every instance, then skips an element, then continues with the next vertex of each instance
    glEnableVertexAttribArray(0);
    // this figures out how to read your attribarray
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, _m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);
    // vertex attribute is any private vector data
    // if you have multiple vectors in a class, it stores the data in order of the first vector's data
    // of every instance, then skips an element, then continues with the next vertex of each instance
    glEnableVertexAttribArray(1);
    // this figures out how to read your attribarray
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, _m_vertexArrayBuffers[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW);
    // vertex attribute is any private vector data
    // if you have multiple vectors in a class, it stores the data in order of the first vector's data
    // of every instance, then skips an element, then continues with the next vertex of each instance
    glEnableVertexAttribArray(2);
    // this figures out how to read your attribarray
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _m_vertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

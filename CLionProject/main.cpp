#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{

    Display display(WIDTH, HEIGHT, "Hello World!");

    Shader shader("../res/basicShader");

    Vertex vertices[] = {Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
                         Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
                         Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0))};

    unsigned int indices[] = { 0, 1 ,2};

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
    Mesh mesh2("../res/monkey3.obj");
    Texture texture("../res/bricks.jpg");
    Camera camera(70.0f, (float)WIDTH/(float)HEIGHT, 0.01f, 1000.0f, glm::vec3(0,0,-3));
    Transform transform;

    float counter = 0.0f;

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        transform.GetPos().x = 1.5f * sinf(counter);
        transform.GetPos().z = 4.0f * cosf(counter);
        transform.GetRot().x = counter;
        transform.GetRot().y = counter;
        transform.GetRot().z = counter;
        //transform.GetScale().y = 2 * sinf(counter);

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform, camera);
        mesh2.Draw();

        display.Update();
        counter += 0.01f;
    }

    return 0;
}
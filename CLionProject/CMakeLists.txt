cmake_minimum_required(VERSION 3.14)
project(OpenGLTutorialProject)
include_directories("/usr/include/SDL2")
include_directories("/usr/include/GL")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 11)

include_directories(&{SDL2_INCLUDE_PATH})
include_directories(&{OPENGL_INCLUDE_DIRS})
include_directories(&{GLEW_INCLUDE_DIRS})

add_executable(OpenGLTutorialProject main.cpp display.cpp display.h shader.cpp shader.h mesh.cpp mesh.h stb_image.c stb_image.h texture.cpp texture.h transform.h camera.h obj_loader.cpp obj_loader.h)

target_link_libraries(OpenGLTutorialProject ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${SDL2_LIBRARY} -lSDL2main -lSDL2
        )  # -mwindows -lmingw32 )
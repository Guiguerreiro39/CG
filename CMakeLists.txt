cmake_minimum_required(VERSION 2.8)

# Project Name
PROJECT(CG_Trabalho)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
find_package(DevIL REQUIRED)
link_libraries(${IL_LIBRARIES} )
include_directories(ยง{IL_INCLUDE_DIR})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

add_executable(${PROJECT_NAME} ./src/engine.cpp ./src/Point.cpp ./src/Shape.cpp ./src/tinyxml2.cpp ./src/Group.cpp ./src/Parser.cpp ./src/Rotation.cpp ./src/Translation.cpp ./src/Scale.cpp ./src/Colour.cpp ./src/Material.cpp ./src/Light.cpp ./src/Operation.cpp ./src/Camera.cpp )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

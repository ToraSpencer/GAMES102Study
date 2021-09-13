cmake_minimum_required(VERSION 3.1)
project(Minimal_Surface)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


# 设置libigl库的搜索路径，即libigl-config.cmake所在的目录。
set(libigl_DIR  /G:/gitRepositories/libigl-main/build)
set(LIBIGL_INCLUDE_DIR  G:/gitRepositories/libigl-main/include)   # libigl库include路径


# 设置openMesh库的搜索路径，即OpenMeshConfig.cmake所在的目录
set(OpenMesh_DIR G:/gitRepositories/openMeshStudy/openMesh8.1_vs2017/share/OpenMesh/cmake)
set(OPENMESH_INCLUDE_DIR G:/gitRepositories/openMeshStudy/openMesh8.1_vs2017/include)


# libigl
option(LIBIGL_WITH_OPENGL            "Use OpenGL"         ON)
option(LIBIGL_WITH_OPENGL_GLFW       "Use GLFW"           ON)


find_package(LIBIGL REQUIRED QUIET)
find_package(OpenMesh REQUIRED)


# Add your project files
file(GLOB SRCFILES *.cpp)
add_executable(${PROJECT_NAME} ${SRCFILES} minimal_surface.h minimal_surface.cpp Base.hpp Base.cpp Harmonic_map.hpp)
target_link_libraries(${PROJECT_NAME} igl::core igl::opengl_glfw)
target_link_libraries(${PROJECT_NAME} ${OpenMesh_LIBS} OpenMeshCore OpenMeshTools)

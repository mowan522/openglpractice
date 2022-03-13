cmake_minimum_required(VERSION 3.12)

#####################################

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

IF(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ELSE()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
ENDIF()

#####################################

project(OldOpenGL_practice1 CXX)
message("Project name is set as: ${PROJECT_NAME}")

#glfw
set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/../external/glfwlib)
find_package(glfw3 REQUIRED)

#OpenGL
find_package(OpenGL REQUIRED)

#####################################

include_directories(
 ${glfw3_INCLUDE_DIR}
 )

add_executable(${PROJECT_NAME}
 main.cpp
 )

target_link_libraries(${PROJECT_NAME}
 ${OPENGL_LIBRARY}
 glfw
 )
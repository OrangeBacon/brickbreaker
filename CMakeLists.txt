# create project
project(brickbreaker)
cmake_minimum_required(VERSION 3.0)

# Dont generate GLFW docs/test/examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# add GLFW
add_subdirectory(libraries/GLFW)
include_directories(libraries/GLFW/include)

# includes
include_directories(src)
include_directories(include)

# add source code
add_subdirectory(src)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# create excecutable and link
add_executable(brickbreaker src/main.cpp)
target_link_libraries(brickbreaker glfw ${GLFW_LIBRARIES} source)
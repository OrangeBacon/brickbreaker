project(brickbreaker)
cmake_minimum_required(VERSION 3.0)

# Dont generate GLFW docs/test/examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(GLFW)

include_directories(src)
include_directories(include)
include_directories(GLFW/include)
#add_subdirectory(src)

add_executable(brickbreaker src/main.cpp)
target_link_libraries(brickbreaker glfw ${GLFW_LIBRARIES}) #src)
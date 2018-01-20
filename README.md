# BrickBreaker

Brickbreaker clone written in c++ using OpenGL and GLFW

# Building
Builds are only tested on windows, but should work for any system with OpenGL that is supported by GLFW

## Windows

build requires MinGW and cmake
```
git clone https://github.com/ScratchOs/brickbreaker.git
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
brickbreaker.exe
```
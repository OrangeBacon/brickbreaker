#ifndef _Shader_h_
#define _Shader_h_

#include <glad/glad.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader {
  public:
    unsigned int ID;
    
    Shader(const GLchar* vertPath, const GLchar* fragPath);

    void use();

    void set1b(const std::string &name, bool value) const;
    void set1i(const std::string &name, int value) const;
    void set1f(const std::string &name, float value) const;
};



#endif
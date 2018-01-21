#include "Shader.hpp"

Shader::Shader(const GLchar* vertPath, const GLchar* fragPath) {
    std::string vertSource;
    std::string fragSource;

    std::ifstream vertFile;
    std::ifstream fragFile;

    vertFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        vertFile.open(vertPath);
        fragFile.open(fragPath);

        std::stringstream vertStream;
        std::stringstream fragStream;

        vertStream << vertFile.rdbuf();
        fragStream << fragFile.rdbuf();

        vertFile.close();
        fragFile.close();

        vertSource = vertStream.str();
        fragSource = fragStream.str();
    } catch(std::ifstream::failure e) {
        std::cout << "Could not load Shader Program \"" << vertPath
          << "\" \"" << fragPath << "\"" << std::endl;
    }

    const char* vShaderCode = vertSource.c_str();
    const char* fShaderCode = fragSource.c_str();

    int success;
    char infolog[512];

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infolog);
        std::cout << "Vertex shader compilation failed: \n" << infolog << std::endl;
    }

    unsigned int fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragShader);

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragShader, 512, nullptr, infolog);
        std::cout << "Fragment shader compilation failed: \n" << infolog << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(ID, 512, nullptr, infolog);
        std::cout << "Program failed to compile: \n" << infolog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

void Shader::use(){
    glUseProgram(ID);
}

void Shader::set1b(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void Shader::set1i(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

void Shader::set1f(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}
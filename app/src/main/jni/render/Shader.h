#pragma once

#include <string>
#include <GLES2/gl2.h>
#include "GLHandle.h"

namespace render {
class Shader {
protected:
  Shader(GLenum shaderType, const std::string& sourceCode);
  ~Shader();

public:
  GLuint getID();
  
private:
  GLHandle id_;
};

  
class VertexShader : public Shader {
public:
  explicit VertexShader(const std::string& sourceCode);
};

class FragmentShader : public Shader {
public:
  explicit FragmentShader(const std::string& sourceCode);
};


}

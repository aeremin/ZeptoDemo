#pragma once

#include <string>
#include "GLHandle.h"

namespace render {
class VertexShader;
class FragmentShader;

class ShaderProgram {
public:
  ShaderProgram(VertexShader& vertexShader, FragmentShader& fragmentShader);
  ~ShaderProgram();

  void setUniform(const std::string& name, float value);

  void makeActive();

private:
  GLHandle id_;
};

}

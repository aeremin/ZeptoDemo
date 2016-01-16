#pragma once

#include <string>
#include "../math/GeomVector.h"
#include "GLHandle.h"

namespace render {
class VertexShader;
class FragmentShader;

class ShaderProgram {
public:
    ShaderProgram(VertexShader& vertexShader, FragmentShader& fragmentShader);
    ~ShaderProgram();

    GLuint  getAttributeLocation(const std::string& name) const;

    void setUniform(const std::string& name, float value);
    void setUniform(const std::string& name, const math::GeomVector2F& value);

    void makeActive();

private:
    GLHandle id_;
};

}

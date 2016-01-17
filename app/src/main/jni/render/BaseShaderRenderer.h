#pragma once
#include <memory>
#include "ShaderProgram.h"
#include "DataFormats.h"

namespace render {

class BaseShaderRenderer {
public:
    void setGlobalOffset(const math::GeomVector2F& offset);
    void setXScale(float xScale);

    void setColor(const math::GeomVector3F& offset);

protected:
    BaseShaderRenderer();

    std::unique_ptr<ShaderProgram> shaderProgram_;

    ArrayBuffer<Vertex2D> verticesBuffer_;
};

}
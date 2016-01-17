#pragma once
#include <memory>
#include "ShaderProgram.h"
#include "DataFormats.h"

namespace render {

class BaseShaderRenderer {
protected:
    BaseShaderRenderer();

    std::unique_ptr<ShaderProgram> shaderProgram_;

    ArrayBuffer<Vertex2D> verticesBuffer_;
};

}
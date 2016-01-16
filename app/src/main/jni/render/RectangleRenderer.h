#pragma once
#include <memory>
#include "../math/Rectangle.h"
#include "ShaderProgram.h"
#include "DataFormats.h"

namespace render {

class RectangleRenderer {
public:
    RectangleRenderer();

    void render(const std::vector<math::Rectangle>& rectangles);

private:
    std::unique_ptr<ShaderProgram> shaderProgram_;
    ArrayBuffer<Vertex2D> verticesBuffer_;
};

}

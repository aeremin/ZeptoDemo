#pragma once

#include <vector>
#include "BaseShaderRenderer.h"
#include "DataFormats.h"
#include "../math/Circle.h"

namespace render {

class CircleRenderer : BaseShaderRenderer {
public:
    CircleRenderer(float xScale);

    void render(const math::Circle& circle);

private:
    std::vector<Vertex2D> vertices_;
    const float xScale_;
};

}

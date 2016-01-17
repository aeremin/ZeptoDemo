#pragma once

#include <vector>
#include "BaseShaderRenderer.h"
#include "DataFormats.h"
#include "../math/Circle.h"

namespace render {

class CircleRenderer : BaseShaderRenderer {
public:
    void render(const math::Circle& circle);

private:
    std::vector<Vertex2D> vertices_;
};

}

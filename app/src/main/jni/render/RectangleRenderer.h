#pragma once
#include "../math/Rectangle.h"
#include "DataFormats.h"
#include "BaseShaderRenderer.h"

namespace render {

class RectangleRenderer : public BaseShaderRenderer {
public:
    void render(const std::vector<math::Rectangle>& rectangles);
};

}

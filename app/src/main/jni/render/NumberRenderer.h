#pragma once

#include "BaseShaderRenderer.h"

namespace render {

class NumberRenderer : public BaseShaderRenderer {
public:
    NumberRenderer();

    void render(uint64_t number, math::GeomVector2F position);

private:
    void generateDigitVertices_();
    std::vector<std::pair<size_t, size_t>> digitOffsetAndPrimitiveCount_;
};

}
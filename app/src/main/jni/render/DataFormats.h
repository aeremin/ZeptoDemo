#pragma once

#include "../math/GeomVector.h"
#include "ArrayBuffer.h"

namespace render {
struct Vertex2D {
    math::GeomVector2F position;

    static void setUpLayout(ArrayBuffer<Vertex2D>& buffer) {
        buffer.setUpFloatAttribute("position", 2, false, offsetof(Vertex2D, position));
    }
};
}
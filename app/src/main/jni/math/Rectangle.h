#ifndef ZEPTODEMO_RECTANGLE_H
#define ZEPTODEMO_RECTANGLE_H

#include "GeomVector.h"

struct Rectangle {
    Rectangle(GeomVector2F firstCorner, GeomVector2F secondCorner)
        : minCorner(min(firstCorner, secondCorner)), maxCorner(max(firstCorner, secondCorner))
    {}

    const GeomVector2F minCorner;
    const GeomVector2F maxCorner;
};


#endif //ZEPTODEMO_RECTANGLE_H

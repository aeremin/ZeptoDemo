#ifndef ZEPTODEMO_CIRCLE_H
#define ZEPTODEMO_CIRCLE_H

#include "GeomVector.h"

struct Circle {
    Circle(GeomVector2F center__, float radius__)
        : center(center__), radius(radius__) {}

    const GeomVector2F center;
    const float radius;
};


#endif //ZEPTODEMO_CIRCLE_H

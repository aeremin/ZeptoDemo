#ifndef ZEPTODEMO_FIELD_H
#define ZEPTODEMO_FIELD_H

#include <deque>

#include "Obstacle.h"

class Field {
public:
    Field(float screenWidthWorld, float screenHeightWorld);

    void update(float offset);

    void render();

private:
    const float screenWidthWorld_, screenHeightWorld_;
    float currentOffset_;
    std::deque<Obstacle> obstacles_;

};


#endif //ZEPTODEMO_FIELD_H

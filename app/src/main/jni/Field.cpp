#include "Field.h"

Field::Field(float screenWidthWorld, float screenHeightWorld)
    : screenWidthWorld_(screenWidthWorld),
      screenHeightWorld_(screenHeightWorld)
{
}

void Field::update(float offset) {
    currentOffset_ = offset;
}

void Field::render() {

}

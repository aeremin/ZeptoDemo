#include "NumberRenderer.h"
#include <deque>
namespace render
{
namespace {
const float cDigitWidth = 0.1f;
const float cDigitSpacing = 0.03f;
}
NumberRenderer::NumberRenderer() {
    generateDigitVertices_();
}

void NumberRenderer::generateDigitVertices_() {
    digitOffsetAndPrimitiveCount_.resize(10);
    std::vector<math::GeomVector2F> digitsPoints(6);
    for (size_t i = 0; i < 6; ++i)
        digitsPoints[i] = cDigitWidth * math::GeomVector2F(float(i % 2), float(i / 2));

    std::vector<std::vector<size_t>> digitDescription(10);
    digitDescription[0] = {0, 1, 5, 4, 0};
    digitDescription[1] = {2, 5, 1};
    digitDescription[2] = {4, 5, 3, 0, 1};
    digitDescription[3] = {4, 5, 2, 3, 0};
    digitDescription[4] = {4, 2, 3, 5, 1};
    digitDescription[5] = {5, 4, 2, 3, 1, 0};
    digitDescription[6] = {5, 2, 0, 1, 3, 2};
    digitDescription[7] = {4, 5, 2, 0};
    digitDescription[8] = {2, 4, 5, 1, 0, 2, 3};
    digitDescription[9] = {3, 2, 4, 5, 3, 0};

    std::vector<Vertex2D> vertices;
    for (int digit = 0; digit < 10; ++digit) {
        digitOffsetAndPrimitiveCount_[digit].first = vertices.size();
        for (auto ind : digitDescription[digit])
            vertices.push_back({digitsPoints[ind]});
        digitOffsetAndPrimitiveCount_[digit].second = digitDescription[digit].size();
    }

    verticesBuffer_.bind();
    verticesBuffer_.setData(vertices);
    verticesBuffer_.unbind();
}

void NumberRenderer::render(uint64_t number, math::GeomVector2F position) {
    std::deque<int> digits;
    while (number > 0) {
        digits.push_front(number % 10);
        number /= 10;
    }

    if (digits.empty())
        digits.push_back(0);

    glLineWidth(3.0f);

    shaderProgram_->makeActive();
    verticesBuffer_.bind();
    verticesBuffer_.setUpLayout(*shaderProgram_);

    for (auto d : digits) {
        setGlobalOffset(-1.0f * position);
        glDrawArrays(GL_LINE_STRIP, digitOffsetAndPrimitiveCount_[d].first,
                                    digitOffsetAndPrimitiveCount_[d].second);
        position += math::GeomVector2F(cDigitWidth + cDigitSpacing, 0.0f);
    }
}
}


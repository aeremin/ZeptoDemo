#include "CircleRenderer.h"

namespace render {
namespace {
const int cCircleResolution = 40;
const float cPi = 4.0f * atan(1.0f);
}

void CircleRenderer::render(const math::Circle& circle) {
    std::vector<Vertex2D> vertices = {{}};
    vertices.reserve(2 + cCircleResolution);
    for (int i = 0; i <= cCircleResolution; ++i) {
        float angle = (2.0 * cPi * i) / cCircleResolution;
        vertices.push_back({circle.radius * math::GeomVector2F(cos(angle), sin(angle))});
    }

    shaderProgram_->makeActive();
    shaderProgram_->setUniform("gOffset", math::GeomVector2F(0.0f, -circle.center[1]));
    verticesBuffer_.bind();
    verticesBuffer_.setUpLayout(*shaderProgram_);
    verticesBuffer_.setData(vertices);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
}

}
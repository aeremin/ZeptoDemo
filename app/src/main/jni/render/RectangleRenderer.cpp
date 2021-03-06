#include "RectangleRenderer.h"
#include "Shader.h"
#include "../math/GeomVector.h"

namespace render {

void RectangleRenderer::render(const std::vector<math::Rectangle>& rectangles) {
    std::vector<Vertex2D> vertices;
    vertices.reserve(6 * rectangles.size());
    for (auto& rect : rectangles) {
        vertices.push_back({rect.minCorner});
        vertices.push_back({math::GeomVector2F(rect.maxCorner[0], rect.minCorner[1])});
        vertices.push_back({rect.maxCorner});

        vertices.push_back({rect.maxCorner});
        vertices.push_back({math::GeomVector2F(rect.minCorner[0], rect.maxCorner[1])});
        vertices.push_back({rect.minCorner});
    }

    shaderProgram_->makeActive();

    verticesBuffer_.bind();
    verticesBuffer_.setUpLayout(*shaderProgram_);
    verticesBuffer_.setData(vertices);

    glDrawArrays(GL_TRIANGLES, 0, 6 * rectangles.size());
}

}

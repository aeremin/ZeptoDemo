#include "RectangleRenderer.h"
#include "Shader.h"
#include "../math/GeomVector.h"

namespace render {

namespace {
auto cVertexShader = R"(
attribute vec2 position;

// Poor man camera matrix
uniform vec2 gOffset;

void main() {
    gl_Position = vec4(position - gOffset, 0.0, 1.0);
})";

auto cFragmentShader = R"(
void main() {
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
)";
}

RectangleRenderer::RectangleRenderer() {
    VertexShader vertexShader(cVertexShader);
    FragmentShader fragmentShader(cFragmentShader);
    shaderProgram_.reset(new ShaderProgram(vertexShader, fragmentShader));
}

void RectangleRenderer::render(const std::vector<math::Rectangle>& rectangles,
                               math::GeomVector2F globalOffset) {
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
    shaderProgram_->setUniform("gOffset", globalOffset);

    verticesBuffer_.bind();
    verticesBuffer_.setUpLayout(*shaderProgram_);
    verticesBuffer_.setData(vertices);

    glDrawArrays(GL_TRIANGLES, 0, 6 * rectangles.size());
}
}

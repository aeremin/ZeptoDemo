#include "BaseShaderRenderer.h"
#include "Shader.h"

namespace render {

namespace {
auto cVertexShader = R"(
attribute vec2 position;

// Poor man camera matrix
uniform vec2 gOffset;
uniform float gXScale;

void main() {
    vec2 transformedPosition = position - gOffset;
    transformedPosition.x /= gXScale;
    gl_Position = vec4(transformedPosition, 0.0, 1.0);
})";

auto cFragmentShader = R"(
uniform vec3 gColor;

void main() {
    gl_FragColor = vec4(gColor, 1.0);
}
)";
}

BaseShaderRenderer::BaseShaderRenderer() {
    VertexShader vertexShader(cVertexShader);
    FragmentShader fragmentShader(cFragmentShader);
    shaderProgram_.reset(new ShaderProgram(vertexShader, fragmentShader));
}

void BaseShaderRenderer::setGlobalOffset(const math::GeomVector2F& offset) {
    shaderProgram_->setUniform("gOffset", offset);
}

void BaseShaderRenderer::setXScale(float xScale) {
    shaderProgram_->setUniform("gXScale", xScale);
}

void BaseShaderRenderer::setColor(const math::GeomVector3F& color) {
    shaderProgram_->setUniform("gColor", color);
}
}
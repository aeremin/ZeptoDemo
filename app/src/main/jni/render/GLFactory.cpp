#include "GLFactory.h"

namespace render {
namespace glfactory {

GLHandle genBuffer() {
    GLuint res;
    glGenBuffers(1, &res);
    return res;
}
}
}


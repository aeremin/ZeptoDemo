#pragma once

#include <GLES2/gl2.h>

namespace render {

class GLHandle
{
public:
    GLHandle(GLuint id) : id_(id) {}
    GLHandle(GLHandle&& other) : id_(other.id_) { other.id_ = -1; }
    GLHandle(const GLHandle& other) = delete;
    const GLHandle& operator=(const GLHandle& other) = delete;

    operator GLuint()   const { return id_; }
    const GLuint& get() const { return id_; }

private:
    GLuint id_;
};

}

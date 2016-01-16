#pragma once

#include <vector>

#include "GLHandle.h"
#include "GLFactory.h"

namespace render {

template<class DataType, GLenum Type>
class BaseBuffer
{
public:
    BaseBuffer();
    ~BaseBuffer();

    void bind();
    void unbind();

    void setData(const std::vector<DataType>& data);

protected:
    GLHandle id_;
};

template<class DataType, GLenum Type>
BaseBuffer<DataType, Type>::BaseBuffer()
        : id_(glfactory::genBuffer()) {}

template<class DataType, GLenum Type>
BaseBuffer<DataType, Type>::~BaseBuffer() {
    glDeleteBuffers(1, &id_.get());
}

template<class DataType, GLenum Type>
void BaseBuffer<DataType, Type>::bind() {
    glBindBuffer(Type, id_);
}

template<class DataType, GLenum Type>
void BaseBuffer<DataType, Type>::unbind() {
    glBindBuffer(Type, 0);
}

template<class DataType, GLenum Type>
void BaseBuffer<DataType, Type>::setData(const std::vector<DataType>& data) {
    glBufferData(Type, sizeof(DataType) * data.size(), data.data(), GL_STATIC_DRAW);
}

}

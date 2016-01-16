#pragma once

#include <string>
#include <GLES2/gl2.h>

#include "BaseBuffer.h"
#include "ShaderProgram.h"

namespace render {

template<class DataType>
class ArrayBuffer : public BaseBuffer<DataType, GL_ARRAY_BUFFER> {
public:
    void setUpLayout(const ShaderProgram &program) {

        currentProgram_ = &program;
        DataType::setUpLayout(*this);
        currentProgram_ = nullptr;
    }

    void setUpFloatAttribute(const std::string& attributeName, size_t count,
                             bool normalized, size_t offset) {
        auto normalizedGL = normalized ? GL_TRUE : GL_FALSE;
        auto attributeIndex = currentProgram_->getAttributeLocation(attributeName);
        glVertexAttribPointer(attributeIndex, count, GL_FLOAT, normalizedGL, sizeof(DataType),
                              reinterpret_cast<GLvoid *>(offset));
        glEnableVertexAttribArray(attributeIndex);
    }

private:
    const ShaderProgram* currentProgram_ = nullptr;
};

}
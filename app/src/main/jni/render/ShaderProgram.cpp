#include "ShaderProgram.h"
#include <cassert>
#include "Shader.h"
#include "../Logging.h"
#include "../math/GeomVector.h"

namespace render {

    ShaderProgram::ShaderProgram(VertexShader& vertexShader, FragmentShader& fragmentShader)
            : id_(glCreateProgram())
    {
        glAttachShader(id_, vertexShader.getID());
        glAttachShader(id_, fragmentShader.getID());
        glLinkProgram(id_);
        glDetachShader(id_, vertexShader.getID());
        glDetachShader(id_, fragmentShader.getID());

        GLint result;
        glGetProgramiv(id_, GL_LINK_STATUS, &result);
        if (result != GL_TRUE) {
            GLint linkLogLength;
            glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &linkLogLength);
            std::string linkLog(linkLogLength + 1, ' ');
            if ( linkLogLength > 0 ) {
                glGetProgramInfoLog(id_, linkLogLength, nullptr, &linkLog[0]);
                glDeleteProgram(id_);
                LOGE("Shader program link error: " + linkLog);
                assert(false);
            }
        }
    }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(id_);
    }

    void ShaderProgram::setUniform(const std::string& name, float value) {
        makeActive();
        auto id = glGetUniformLocation(id_, name.c_str());
        assert(id != -1);
        glUniform1f(id, value);
    }

    void ShaderProgram::setUniform(const std::string& name, const math::GeomVector2F& value) {
        makeActive();
        auto id =glGetUniformLocation(id_, name.c_str());
        assert(id != -1);
        glUniform2fv(id, 1, value.data());
    }

    void ShaderProgram::makeActive() {
        glUseProgram(id_);
    }

    GLuint ShaderProgram::getAttributeLocation(const std::string& name) const {
        return glGetAttribLocation(id_, name.c_str());
    }
}
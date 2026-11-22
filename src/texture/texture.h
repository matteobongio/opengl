#pragma once

#include <glad/glad.h>
#include <string>

class Texture2D {
public:
    Texture2D(std::string const &file);
    Texture2D(Texture2D const &) = delete;
    Texture2D operator=(Texture2D const &) = delete;
    ~Texture2D();
    void bind() const;
    GLuint ID();
    size_t GetWidth();
    size_t GetHeight();
private:
    GLuint m_id;
    int m_width, m_height, m_components;
    unsigned char *m_data = nullptr;
    GLint m_internalFormat;
    GLenum m_imageFormat;
    GLint m_wrapS, m_wrapT;
};

inline GLuint Texture2D::ID()
{
    return m_id;
}

inline size_t Texture2D::GetHeight()
{
    return m_height;
}

inline size_t Texture2D::GetWidth()
{
    return m_width;
}

inline void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_id);
}

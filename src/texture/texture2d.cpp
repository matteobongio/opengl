#include "texture.ih"
#include <filesystem>
#include <stdexcept>

Texture2D::Texture2D(std::string const &file) :
    m_internalFormat(GL_RGB),
    m_imageFormat(GL_RGB),
    m_wrapS(GL_REPEAT),
    m_wrapT(GL_REPEAT)
{
    stbi_set_flip_vertically_on_load(true);
    std::filesystem::path full = std::filesystem::path(RESOURCES) / file;
    m_data = stbi_load(full.c_str(), &m_width, &m_height, &m_components,  0);

    if (!m_data)
        throw std::runtime_error(file);

    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, m_internalFormat, m_width, m_height, 0, m_imageFormat, GL_UNSIGNED_BYTE, m_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(m_data);
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &m_id);
}

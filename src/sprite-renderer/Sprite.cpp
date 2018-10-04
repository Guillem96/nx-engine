#include "sprite-renderer/Sprite.h"

Sprite::Sprite(const std::string &path,
               const Vector2 &positon,
               const Vector2 &scale) : m_path(path),
                                       m_position(positon),
                                       m_scale(scale)
{
}

Sprite::Sprite(const std::string &path,
               const Vector2 &positon,
               const Vector2 &scale,
               unsigned int align) : m_path(path),
                                     m_position(positon),
                                     m_scale(scale),
                                     m_screenAlignment(align)
{
}

Sprite::~Sprite()
{
}

const Vector2 &Sprite::getPosition()
{
    return m_position;
}

const Vector2 &Sprite::getScale()
{
    return m_scale;
}

const Vector2 &Sprite::getSize()
{
    return m_size;
}

unsigned int Sprite::getScreenAlignment()
{
    return m_screenAlignment;
}

void Sprite::setPosition(const Vector2 &positon)
{
    m_position = positon;
}

void Sprite::setScale(const Vector2 &scale)
{
    m_scale = scale;
}

void Sprite::setAlignment(unsigned int align)
{
    m_screenAlignment = align;
}

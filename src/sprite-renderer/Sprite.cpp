#include "sprite-renderer/Sprite.h"

Sprite::Sprite(const std::string &path,
               const Vector2 &positon,
               const Vector2 &scale) : IDrawable(positon),
                                       m_path(path),
                                       m_scale(scale)
{
}

Sprite::Sprite(const std::string &path,
               const Vector2 &positon,
               const Vector2 &scale,
               unsigned int align) : IDrawable(positon, align),
                                     m_path(path),
                                     m_scale(scale)
{
}

Sprite::~Sprite()
{
}

const Vector2 &Sprite::getScale()
{
    return m_scale;
}

const Vector2 &Sprite::getSize()
{
    return m_size;
}

void Sprite::setScale(const Vector2 &scale)
{
    m_scale = scale;
}

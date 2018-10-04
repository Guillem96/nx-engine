#pragma once

#include <string>

#include "common/IDrawable.h"

class SpriteRenderer;

class Sprite : public IDrawable
{
    friend class SpriteRenderer;

  private:
    std::string m_path;
    Vector2 m_scale;
    Vector2 m_size; //> Size is set by SpriteRenderer once the sprite queued to render

  public:
    Sprite(const std::string &path, const Vector2 &positon, const Vector2 &scale);
    Sprite(const std::string &path, const Vector2 &positon, const Vector2 &scale, unsigned int align);
    ~Sprite();

    const Vector2 &getScale();
    const Vector2 &getSize(); //> Will only work after sprite is added to the sprite renderer

    void setScale(const Vector2 &scale);
};
#pragma once

#include <string>

#include "vectors/Vector2.h"
#include "common/ScreenAlignFlags.h"

class SpriteRenderer;

class Sprite
{
    friend class SpriteRenderer;

  private:
    Vector2 m_position;
    Vector2 m_scale;
    Vector2 m_size; //> Size is set by SpriteRenderer once the sprite queued to render
    std::string m_path;
    unsigned int m_screenAlignment = ScreenAlignFlags::FREE;

  public:
    Sprite(const std::string &path, const Vector2 &positon, const Vector2 &scale);
    Sprite(const std::string &path, const Vector2 &positon, const Vector2 &scale, unsigned int align);
    ~Sprite();

    const Vector2 &getPosition();
    const Vector2 &getScale();
    const Vector2 &getSize(); //> Will only work after sprite is added to the sprite renderer
    unsigned int getScreenAlignment();

    void setPosition(const Vector2 &positon);
    void setScale(const Vector2 &scale);
    void setAlignment(unsigned int align);
};
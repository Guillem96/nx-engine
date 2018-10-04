#pragma once

#include "vectors/Vector2.h"
#include "common/ScreenAlignFlags.h"

class IDrawable
{
  protected:
    Vector2 m_position;
    unsigned int m_align = ScreenAlignFlags::FREE;

    float m_paddingLeft = 5.0f;
    float m_paddingTop = 5.0f;
    float m_paddingRight = 5.0f;
    float m_paddingBottom = 5.0f;

  public:
    IDrawable(const Vector2 &position) : m_position(position) {}
    IDrawable(const Vector2 &position, unsigned int align) : m_position(position), m_align(align) {}
    virtual ~IDrawable() {}

    const Vector2 &getPosition() const { return m_position; }
    unsigned int getAlignmentFlags() const { return m_align; }

    float getPaddingLeft() const { return m_paddingLeft; }
    float getPaddingRight() const { return m_paddingRight; }
    float getPaddingTop() const { return m_paddingTop; }
    float getPaddingBottom() const { return m_paddingBottom; }

    void setPosition(const Vector2 &position) { m_position = position; }
    void setAlignmentFlags(unsigned int flags) { m_align = flags; }

    void setPaddings(float left, float top, float right, float bottom)
    {
        setPaddingLeft(left);
        setPaddingTop(top);
        setPaddingRight(right);
        setPaddingBottom(bottom);
    }

    void setPaddingLeft(float p) { m_paddingLeft = p; }
    void setPaddingRight(float p) { m_paddingRight = p; }
    void setPaddingTop(float p) { m_paddingTop = p; }
    void setPaddingBottom(float p) { m_paddingBottom = p; }
};
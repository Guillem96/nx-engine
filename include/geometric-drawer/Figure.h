#pragma once

#include "vectors/Vector2.h"
#include "common/Color.h"

class Figure
{
  private:
    Vector2 m_position;
    Color m_color;
    float m_strokeWidth;
    bool m_isFilled;

  public:
    Figure(const Vector2 &position, const Color &color, float strokeWidth, bool filled)
        : m_position(position),
          m_color(color),
          m_strokeWidth(strokeWidth),
          m_isFilled(filled) {}

    virtual ~Figure() {}

    const Vector2 &getPosition() { return m_position; }
    const Color &getColor() { return m_color; }
    float getStrokeWidth() { return m_strokeWidth; }
    bool getIsFilled() { return m_isFilled; }

    void setPosition(const Vector2 &position) { m_position = position; }
    void setColor(const Color &color) { m_color = color; }
    void setStrokeWidth(float width) { m_strokeWidth = width; }
    void setIsFilled(bool isFilled) { m_isFilled = isFilled; }
};
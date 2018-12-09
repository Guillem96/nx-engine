#pragma once

#include "geometric-drawer/Figure.h"

class Rectangle : public Figure
{
  private:
    Vector2 m_size;
    Vector2 m_position;

  public:
    // Position referes to bottom left vertex
    Rectangle(const Vector2 &position, const Color &strokeColor, const Color &backgroundColor, bool filled, const Vector2 &size);

    virtual ~Rectangle() {}

    const Vector2 &getSize() { return m_size; }
    const Vector2 &getPosition() { return m_position; }

    void setSize(const Vector2 &size) { m_size = size; }
    void setPosition(const Vector2 &position) { m_position = position; }
};
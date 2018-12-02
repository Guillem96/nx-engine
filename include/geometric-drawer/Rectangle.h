#pragma once

#include "geometric-drawer/Figure.h"

class Rectangle : public Figure
{
  private:
    Vector2 m_size;

  public:
    // Position referes to bottom left vertex
    Rectangle(const Vector2 &position, const Color &color, float strokeWidth, bool filled, const Vector2 &size)
        : Figure(position, color, strokeWidth, filled), m_size(size) {}
    virtual ~Rectangle() {}

    const Vector2 &getSize() { return m_size; }

    void setSize(const Vector2 &size) { m_size = size; }
};
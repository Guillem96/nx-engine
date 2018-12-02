#pragma once

#include "geometric-drawer/Figure.h"

class Ellipse : public Figure
{
  private:
    Vector2 m_radius;

  public:
    Ellipse(const Vector2 &position, const Color &color, float strokeWidth, bool filled, const Vector2 &radius)
        : Figure(position, color, strokeWidth, filled), m_radius(radius) {}
    virtual ~Ellipse() {}

    const Vector2 &getRadius() { return m_radius; }

    void setRadius(const Vector2 &radius) { m_radius = radius; }
};
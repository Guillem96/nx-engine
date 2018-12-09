#pragma once

#include "geometric-drawer/Figure.h"

class Ellipse : public Figure
{
  private:
    Vector2 m_center;
    Vector2 m_radius;

  public:
    Ellipse(const Vector2 &center, const Color &strokeColor, const Color &backgroundColor, bool filled, const Vector2 &radius);
    virtual ~Ellipse() {}

    const Vector2 &getCenter() { return m_center; }
    const Vector2 &getRadius() { return m_radius; }

    void setRadius(const Vector2 &radius) { m_radius = radius; }
    void setCenter(const Vector2 &center) { m_center = center; }

    virtual void draw(SDL_Renderer *renderer) override;
};
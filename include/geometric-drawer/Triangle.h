#pragma once

#include "geometric-drawer/Figure.h"
#include "vectors/Vector3.h"

class Triangle : public Figure
{
  private:
    Vector3 m_points;

  public:
    Triangle(const Color &color, float strokeWidth, bool filled, const Vector3 &points)
        : Figure(Vector2(), color, strokeWidth, filled), m_points(points) {}
    virtual ~Triangle() {}

    const Vector3 &getPoints() { return m_points; }

    void setPoints(const Vector3 &points) { m_points = points; }
};
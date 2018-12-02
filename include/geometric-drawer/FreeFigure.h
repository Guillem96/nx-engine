#pragma once

#include "geometric-drawer/Figure.h"
#include <vector>

class FreeFigure : public Figure
{
  private:
    std::vector<Vector2> m_points;

  public:
    FreeFigure(const Color &color, float strokeWidth, bool filled, const std::vector<Vector2> &points)
        : Figure(Vector2(), color, strokeWidth, filled), m_points(points) {}
    virtual ~FreeFigure() {}

    const std::vector<Vector2> &getPoints() { return m_points; }

    void setPoints(const std::vector<Vector2> &points) { m_points = points; }
};
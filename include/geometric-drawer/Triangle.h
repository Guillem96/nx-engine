#pragma once

#include "geometric-drawer/Figure.h"

class Triangle : public Figure
{
  public:
    Triangle(const std::vector<Vector2 &> &points, const Color &strokeColor, const Color &backgroundColor, float strokeWidth, bool filled)
        : Figure(points, strokeColor, backgroundColor, strokeWidth, filled) {}
    virtual ~Triangle() {}
}

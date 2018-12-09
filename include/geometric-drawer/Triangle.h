#pragma once

#include "geometric-drawer/Figure.h"

class Triangle : public Figure
{
  public:
    Triangle(const std::vector<Vector2 *> &points, const Color &strokeColor, const Color &backgroundColor, bool filled, bool bordered)
        : Figure(points, strokeColor, backgroundColor, filled, bordered) {}
    virtual ~Triangle() {}
};

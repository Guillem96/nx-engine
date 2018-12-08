#pragma once

#include "geometric-drawer/Figure.h"

class Line : public Figure
{
  public:
    Line(const std::vector<Vector2 *> &points, const Color &color, float strokeWidth)
        : Figure(points, color, color, strokeWidth, false) {}
    virtual ~Line() {}

    void draw(SDL_Renderer *renderer);
};

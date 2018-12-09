#pragma once

#include "geometric-drawer/Figure.h"

class Line : public Figure
{
  private:
    float m_width = 2.0f;

  public:
    Line(const std::vector<Vector2 *> &points, const Color &color, float width)
        : Figure(points, color, color, false, false), m_width(width) {}
    virtual ~Line() {}

    void draw(SDL_Renderer *renderer);
};

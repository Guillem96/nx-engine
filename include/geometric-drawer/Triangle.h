#pragma once

#include "geometric-drawer/Figure.h"

/**
 * @brief Shape representing a Triangle
 * 
 */
class Triangle : public Figure
{
  public:
    /**
     * @brief Construct a new Triangle object
     * Not recommended.
     * @see FigureBuilder
     */
    Triangle(const std::vector<Vector2 *> &points, const Color &strokeColor, const Color &backgroundColor, bool filled, bool bordered)
        : Figure(points, strokeColor, backgroundColor, filled, bordered) {}
    virtual ~Triangle() {}
};

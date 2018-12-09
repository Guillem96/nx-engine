#pragma once

#include "geometric-drawer/Figure.h"
#include "geometric-drawer/Rectangle.h"
#include "geometric-drawer/Ellipse.h"
#include "geometric-drawer/Triangle.h"
#include "geometric-drawer/Line.h"
#include "common/Colors.h"

class FigureBuilder
{
  private:
    bool m_isEllipse = false;
    bool m_isRectangle = false;

    // Figure
    std::vector<Vector2 *> m_points;
    Color m_strokeColor = Colors::BLACK;
    Color m_backgroundColor = Color(0, 0, 0, 0);
    bool m_isFilled = false;

    // Ellipse
    Vector2 m_center;
    Vector2 m_radius;
    bool m_centerCalled = false;
    bool m_radiusCalled = false;

    // Rectangle
    Vector2 m_position;
    Vector2 m_size;

    // Line
    float m_width = 2.0f;

  public:
    FigureBuilder() {}
    ~FigureBuilder() {}

    FigureBuilder *point(Vector2 *point);
    FigureBuilder *size(const Vector2 &size);
    FigureBuilder *position(const Vector2 &position);
    FigureBuilder *radius(const Vector2 &radius);
    FigureBuilder *center(const Vector2 &center);
    FigureBuilder *width(float width);
    FigureBuilder *strokeColor(const Color &color);
    FigureBuilder *backgroundColor(const Color &color);
    FigureBuilder *color(const Color &color);
    FigureBuilder *filled();

    Figure *build();
};
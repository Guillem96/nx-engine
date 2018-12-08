#include "geometric-drawer/FigureBuilder.h"

FigureBuilder *FigureBuilder::point(Vector2 *point)
{
    m_points.push_back(point);
    return this;
}

FigureBuilder *FigureBuilder::size(Vector2 *size)
{
    m_isRectangle = true;
    m_size = *size;
    return this;
}

FigureBuilder *FigureBuilder::position(Vector2 *position)
{
    m_isRectangle = true;
    m_position = *position;
    return this;
}

FigureBuilder *FigureBuilder::radius(Vector2 *radius)
{
    m_isEllipse = true;
    m_radiusCalled = true;
    m_radius = *radius;
    return this;
}

FigureBuilder *FigureBuilder::center(Vector2 *center)
{
    m_isEllipse = true;
    m_centerCalled = true;
    m_center = *center;
    return this;
}

FigureBuilder *FigureBuilder::strokeWidth(float width)
{
    m_strokeWidth = width;
    return this;
}

FigureBuilder *FigureBuilder::strokeColor(const Color &color)
{
    m_strokeColor = color;
    return this;
}

FigureBuilder *FigureBuilder::color(const Color &color)
{
    m_strokeColor = color;
    m_backgroundColor = color;
    return this;
}

FigureBuilder *FigureBuilder::backgroundColor(const Color &color)
{
    m_backgroundColor = color;
    return this;
}

FigureBuilder *FigureBuilder::filled()
{
    m_isFilled = true;
    return this;
}

Figure *FigureBuilder::build()
{
    if (m_isRectangle && m_isEllipse)
        return nullptr;

    if (m_points.size() == 2)
        return new Line(m_points, m_strokeColor, m_strokeWidth);

    if (m_isRectangle)
        return new Rectangle(m_position, m_strokeColor, m_backgroundColor, m_strokeWidth, m_isFilled, m_size);

    if (m_isEllipse && m_centerCalled && m_radiusCalled)
        return new Ellipse(m_center, m_strokeColor, m_backgroundColor, m_strokeWidth, m_isFilled, m_radius);
    else if (m_isEllipse && (!m_centerCalled || m_radiusCalled))
        return nullptr;

    if (m_points.size() == 3)
        return new Triangle(m_points, m_strokeColor, m_backgroundColor, m_strokeWidth, m_isFilled);

    return new Figure(m_points, m_strokeColor, m_backgroundColor, m_strokeWidth, m_isFilled);
}
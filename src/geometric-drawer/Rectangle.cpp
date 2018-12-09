#include "geometric-drawer/Rectangle.h"

Rectangle::Rectangle(const Vector2 &position,
                     const Color &strokeColor,
                     const Color &backgroundColor,
                     float strokeWidth,
                     bool filled,
                     const Vector2 &size) : Figure(std::vector<Vector2 *>(),
                                                   strokeColor,
                                                   backgroundColor,
                                                   strokeWidth, filled)
{
    m_size = size;
    m_position = position;

    std::vector<Vector2 *> points;
    points.push_back(new Vector2(m_position.x, m_position.y));
    points.push_back(new Vector2(position.x, position.y + size.y));
    points.push_back(new Vector2(position.x + size.x, position.y + size.y));
    points.push_back(new Vector2(position.x + size.x, position.y));

    setPoints(points);
}
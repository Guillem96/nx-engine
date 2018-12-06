#include "geometric-drawer/Rectangle.h"

Rectangle::Rectangle(const Vector2 &position,
                     const Color &strokeColor,
                     const Color &backgroundColor,
                     float strokeWidth,
                     bool filled,
                     const Vector2 &size)
{
    m_size = size;
    m_position = position;

    std::vector<Vector2 *> points;
    points.push_back(&m_position);
    points.push_back(new Vector2(position.x + size.x, position.y));
    points.push_back(new Vector2(position.x, position.y + size.y));
    points.push_back(new Vector2(position.x + size.x, position.y + size.y));

    Figure(points, strokeColor, backgroundColor, strokeWidth, filled);
}
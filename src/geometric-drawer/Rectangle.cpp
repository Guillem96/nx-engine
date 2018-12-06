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
    std::vector<Vector2> points{
        &position,
        new Vector2(position.x + size.x, position.y),
        new Vector2(position.x, position.y + size.y),
        new Vector2(position.x + size.x, position.y + size.y)};

    Figure(points, strokeColor, backgroundColor, strokeWidth, filled);
}
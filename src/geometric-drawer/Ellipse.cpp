#include "geometric-drawer/Ellipse.h"

Ellipse::Ellipse(const Vector2 &center,
                 const Color &strokeColor,
                 const Color &backgroundColor,
                 float strokeWidth, bool filled,
                 const Vector2 &radius)
{
    m_center = center;
    m_radius = radius;
    Figure(std::vector<Vector2 *>(), strokeColor, backgroundColor, strokeWidth, filled);
}

void Ellipse::draw()
{
}
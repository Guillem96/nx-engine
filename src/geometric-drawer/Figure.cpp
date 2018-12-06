#include "geometric-drawer/Figure.h"

Figure::~Figure()
{
    for (Vector2 *point : m_points)
    {
        delete point;
    }

    m_points.clear();
}

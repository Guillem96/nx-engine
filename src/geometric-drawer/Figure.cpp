#include "geometric-drawer/Figure.h"

Figure::~Figure()
{
    for (Vector2 *point : m_points)
    {
        delete point;
    }

    m_points.clear();
}

void Figure::draw(SDL_Renderer *renderer)
{
    // Only supporting polygons of at maximum 16 vertices
    std::vector<Vector2 *> vertices = getPoints();

    if (vertices.size() > 16)
        return;

    // Generate vx and vy
    Sint16 vx[16];
    Sint16 vy[16];

    for (size_t i = 0; i < vertices.size(); i++)
    {
        vx[i] = vertices[i]->x;
        vy[i] = vertices[i]->y;
    }

    // Render the figure body
    SDL_Color bodyColor = getBackgroundColor().get();
    int result = filledPolygonRGBA(renderer, vx, vy, vertices.size(), bodyColor.r, bodyColor.g, bodyColor.b, bodyColor.a);

    if (result != 0)
        return;

    // Render figure stroke
    SDL_Color strokeColor = getStrokeColor().get();
    polygonRGBA(renderer, vx, vy, vertices.size(), strokeColor.r, strokeColor.g, strokeColor.b, strokeColor.a);
}

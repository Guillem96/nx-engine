#include "geometric-drawer/Line.h"

void Line::draw(SDL_Renderer *renderer)
{
    std::vector<Vector2 *> vertices = getPoints();
    SDL_Color color = getStrokeColor().get();
    thickLineRGBA(renderer,
                  vertices[0]->x, vertices[0]->y,
                  vertices[1]->x, vertices[1]->y,
                  getStrokeWidth(),
                  color.r, color.g, color.b, color.a);
}
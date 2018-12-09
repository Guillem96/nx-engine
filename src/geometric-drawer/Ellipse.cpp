#include "geometric-drawer/Ellipse.h"

Ellipse::Ellipse(const Vector2 &center,
                 const Color &strokeColor,
                 const Color &backgroundColor,
                 float strokeWidth, bool filled,
                 const Vector2 &radius) : Figure(std::vector<Vector2 *>(), strokeColor, backgroundColor, strokeWidth, filled)
{
    m_center = center;
    m_radius = radius;
}

void Ellipse::draw(SDL_Renderer *renderer)
{
    // Render the figure body
    if (getIsFilled())
    {
        SDL_Color bodyColor = getBackgroundColor().get();
        int result = filledEllipseRGBA(renderer,
                                       getCenter().x, getCenter().y,
                                       getRadius().x, getRadius().y,
                                       bodyColor.r, bodyColor.g, bodyColor.b, bodyColor.a);

        if (result != 0)
            return;
    }

    // Render figure stroke
    SDL_Color strokeColor = getStrokeColor().get();
    ellipseRGBA(renderer,
                getCenter().x, getCenter().y,
                getRadius().x, getRadius().y,
                strokeColor.r, strokeColor.g, strokeColor.b, strokeColor.a);
}
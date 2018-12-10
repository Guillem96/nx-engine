#pragma once

#include "geometric-drawer/Figure.h"

/**
 * @brief Shape representing an Ellipse
 * 
 */
class Ellipse : public Figure
{
  private:
    Vector2 m_center;
    Vector2 m_radius;

  public:
    /**
     * @brief Construct a new Ellipse object
     * Not recommended.
     * @see FigureBuilder
     */
    Ellipse(const Vector2 &center, const Color &strokeColor, const Color &backgroundColor, bool filled, bool bordered, const Vector2 &radius);
    virtual ~Ellipse() {}

    /**
     * @brief Get the Center of the ellipse
     * 
     * @return The center of the ellipse
     */
    const Vector2 &getCenter() { return m_center; }

    /**
     * @brief Get the Radius of the ellipse
     * 
     * @return the radius of the ellipse
     */
    const Vector2 &getRadius() { return m_radius; }

    /**
     * @brief Set the Radius
     * 
     * @param radius New value of the radius
     */
    void setRadius(const Vector2 &radius) { m_radius = radius; }

    /**
     * @brief Set the Center
     * 
     * @param center New center position
     */
    void setCenter(const Vector2 &center) { m_center = center; }

    /**
     * @brief Renders the ellipse
     * 
     * @param renderer SDL_Renderer of the current SDL_Window
     */
    virtual void draw(SDL_Renderer *renderer) override;
};
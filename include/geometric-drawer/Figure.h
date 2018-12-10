#pragma once

#include <vector>
#include "vectors/Vector2.h"
#include "common/Color.h"

#include <SDL2/SDL2_gfxPrimitives.h>

class Figure
{
  private:
    std::vector<Vector2 *> m_points;
    Color m_strokeColor;
    Color m_backgroundColor;
    bool m_isFilled;
    bool m_isBordered;

  public:
    Figure() {}

    /**
     * @brief Construct a new Figure object
     * Not recommended.
     * @see FigureBuilder
     * @param points Vertices of the figure
     * @param strokeColor Border color
     * @param backgroundColor Color that will be used to fill the figure body
     * @param filled Is figure filled?
     * @param bordered Is figure bordered?
     */
    Figure(const std::vector<Vector2 *> &points, const Color &strokeColor,
           const Color &backgroundColor,
           bool filled,
           bool bordered)
        : m_points(points),
          m_strokeColor(strokeColor),
          m_backgroundColor(backgroundColor),
          m_isFilled(filled),
          m_isBordered(bordered) {}

    virtual ~Figure();

    /**
     * @brief Get the vertices
     * 
     * @return The figure's vertices 
     */
    std::vector<Vector2 *> &getPoints() { return m_points; }

    /**
     * @brief Get the Stroke Color 
     * 
     * @return The color of the border
     */
    const Color &getStrokeColor() { return m_strokeColor; }

    /**
     * @brief Get the Background Color
     * 
     * @return The color of the background
     */
    const Color &getBackgroundColor() { return m_backgroundColor; }

    /**
     * @brief Get the Is Filled
     * 
     * @return true In case figure is filled
     * @return false In case figure is not filled
     */
    bool getIsFilled() { return m_isFilled; }

    /**
     * @brief Get the Is Bordered
     * 
     * @return true In case figure has a border
     * @return false In case figure is not bordered 
     */
    bool getIsBordered() { return m_isBordered; }

    /**
     * @brief Set the new vertices
     * 
     * @param points New vertices of the figure
     */
    void setPoints(const std::vector<Vector2 *> &points) { m_points = points; }

    /**
     * @brief Set the Stroke Color object
     * 
     * @param color New color of the stroke 
     */
    void setStrokeColor(const Color &color) { m_strokeColor = color; }

    /**
     * @brief Set the Background Color object
     * 
     * @param color New background's color
     */
    void setBackgroundColor(const Color &color) { m_backgroundColor = color; }

    /**
     * @brief Set the Is Filled object
     * 
     * @param isFilled If figure should be filled or not
     */
    void setIsFilled(bool isFilled) { m_isFilled = isFilled; }

    /**
     * @brief Set the Is Bordered object
     * 
     * @param isBordered If figure should have stroke or not
     */
    void setIsBordered(bool isBordered) { m_isBordered = isBordered; }

    /**
     * @brief Renders the figure
     * 
     * @param renderer SDL_Renderer of the current sdl window 
     */
    virtual void draw(SDL_Renderer *renderer);
};
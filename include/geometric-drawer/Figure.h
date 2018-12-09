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

    std::vector<Vector2 *> &getPoints() { return m_points; }
    const Color &getStrokeColor() { return m_strokeColor; }
    const Color &getBackgroundColor() { return m_backgroundColor; }
    bool getIsFilled() { return m_isFilled; }
    bool getIsBordered() { return m_isBordered; }

    void setPoints(const std::vector<Vector2 *> &points) { m_points = points; }
    void setStrokeColor(const Color &color) { m_strokeColor = color; }
    void setBackgroundColor(const Color &color) { m_backgroundColor = color; }
    void setIsFilled(bool isFilled) { m_isFilled = isFilled; }
    void setIsBordered(bool isBordered) { m_isBordered = isBordered; }

    virtual void draw(SDL_Renderer *renderer);
};
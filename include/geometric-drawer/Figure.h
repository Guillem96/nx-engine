#pragma once

#include <vector>
#include "vectors/Vector2.h"
#include "common/Color.h"

class Figure
{
  private:
    std::vector<Vector2 *> m_points;
    Color m_strokeColor;
    Color m_backgroundColor;
    float m_strokeWidth;
    bool m_isFilled;

  public:
    Figure() {}

    Figure(const std::vector<Vector2 *> &points, const Color &strokeColor,
           const Color &backgroundColor,
           float strokeWidth,
           bool filled)
        : m_points(points),
          m_strokeColor(strokeColor),
          m_backgroundColor(backgroundColor),
          m_strokeWidth(strokeWidth),
          m_isFilled(filled) {}

    virtual ~Figure();

    std::vector<Vector2 *> &getPoints() { return m_points; }
    const Color &getStrokeColor() { return m_strokeColor; }
    const Color &getBackgroundColor() { return m_backgroundColor; }
    float getStrokeWidth() { return m_strokeWidth; }
    bool getIsFilled() { return m_isFilled; }

    void setPoints(const std::vector<Vector2 *> &points) { m_points = points; }
    void setStrokeColor(const Color &color) { m_strokeColor = color; }
    void setBackgroundColor(const Color &color) { m_backgroundColor = color; }
    void setStrokeWidth(float width) { m_strokeWidth = width; }
    void setIsFilled(bool isFilled) { m_isFilled = isFilled; }

    virtual void draw();
};
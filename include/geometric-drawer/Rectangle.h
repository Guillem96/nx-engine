#pragma once

#include "geometric-drawer/Figure.h"

/**
 * @brief Shape representing a recatangle
 * 
 */
class Rectangle : public Figure
{
  private:
    Vector2 m_size;
    Vector2 m_position;

  public:
    /**
     * @brief Construct a new Rectangle object
     * Not recommended.
     * @see FigureBuilder
     */
    Rectangle(const Vector2 &position, const Color &strokeColor, const Color &backgroundColor, bool filled, bool bordered, const Vector2 &size);

    virtual ~Rectangle() {}

    const Vector2 &getSize() { return m_size; }
    const Vector2 &getPosition() { return m_position; }

    void setSize(const Vector2 &size) { m_size = size; }
    void setPosition(const Vector2 &position) { m_position = position; }
};
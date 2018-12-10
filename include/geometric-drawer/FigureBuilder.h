#pragma once

#include "geometric-drawer/Figure.h"
#include "geometric-drawer/Rectangle.h"
#include "geometric-drawer/Ellipse.h"
#include "geometric-drawer/Triangle.h"
#include "geometric-drawer/Line.h"
#include "common/Colors.h"

/**
 * @brief Fluent api to easily build figures
 * 
 */
class FigureBuilder
{
  private:
    bool m_isEllipse = false;
    bool m_isRectangle = false;

    // Figure
    std::vector<Vector2 *> m_points;
    Color m_strokeColor = Colors::BLACK;
    Color m_backgroundColor = Color(0, 0, 0, 0);
    bool m_isFilled = false;
    bool m_isBordered = false;

    // Ellipse
    Vector2 m_center;
    Vector2 m_radius;
    bool m_centerCalled = false;
    bool m_radiusCalled = false;

    // Rectangle
    Vector2 m_position;
    Vector2 m_size;

    // Line
    float m_width = 2.0f;

  public:
    FigureBuilder() {}
    ~FigureBuilder() {}

    /**
     * @brief Adds a point to figure
     * 
     * @param point Vector2 that represents the new point
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *point(Vector2 *point);

    /**
     * @brief Sets the size of a rectangle
     * 
     * @param size Vector2 where x is the width and y is the height
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *size(const Vector2 &size);

    /**
     * @brief Sets the position of a rectangle
     * Position will be the bottom right vertex
     * @param position Vector2 representing the position
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *position(const Vector2 &position);

    /**
     * @brief Set the radius of ellipse
     * Can only be called when creating an ellipse
     * @param radius 
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *radius(const Vector2 &radius);

    /**
     * @brief Set the center position of an ellipse
     * Can only be called when creating an ellipse
     * @param center Vector2 representing the center position
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *center(const Vector2 &center);

    /**
     * @brief Set the width of a line
     * Can only be called when creating a line
     * @param width 
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *width(float width);

    /**
     * @brief Set the color of the border
     * 
     * @param color Color of the border
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *strokeColor(const Color &color);

    /**
     * @brief Set background's color
     * 
     * @param color Color of the figure body
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *backgroundColor(const Color &color);

    /**
     * @brief Set both colors. StrokeColor and BackgroundColor
     * Usefull when creating a line
     * @param color Color
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *color(const Color &color);

    /**
     * @brief If it is called then figure will be filled
     * 
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *filled();

    /**
     * @brief If it is called, then the figure will have border
     * 
     * @return FigureBuilder* the current status of FigureBuilder (Fluent api)
     */
    FigureBuilder *bordered();

    /**
     * @brief Build the figure with the previously set status
     * 
     * @return Figure* the built figure or nullptr in case of incoherent status
     */
    Figure *build();
};
#pragma once

#include <SDL2/SDL.h>

class Color
{
  private:
    SDL_Color m_color;

  public:
    constexpr Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) : m_color({red, green, blue, alpha})
    {
    }

    constexpr Color(Uint8 red, Uint8 green, Uint8 blue) : m_color({red, green, blue, 255})
    {
    }

    const SDL_Color &get() const { return m_color; }
};

class Colors
{
  public:
    static constexpr Color WHITE = Color(0, 0, 0);
    static constexpr Color BLACK = Color(255, 255, 255);
    static constexpr Color RED = Color(255, 0, 0);
    static constexpr Color GREEN = Color(0, 255, 0);
    static constexpr Color BLUE = Color(0, 0, 255);
    static constexpr Color WHITESMOKE = Color(76, 76, 76);
    static constexpr Color DARK = Color(235, 235, 235);
};
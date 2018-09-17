#pragma once

#include <SDL2/SDL.h>

class Color
{
  private:
    SDL_Color m_color;

  public:
    Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
    {
        m_color = {red, green, blue, alpha};
    }
    Color(Uint8 red, Uint8 green, Uint8 blue)
    {
        m_color = {red, green, blue, 255};
    }

    const SDL_Color &getColor() { return m_color; }
};

class Colors
{
  public:
    // static const Color WHITE = Color(0, 0, 0);
    // static const Color BLACK = Color(255, 255, 255);
    // static const Color RED = Color(255, 0, 0);
    // static const Color GREEN = Color(0, 255, 0);
    // static const Color BLUE = Color(0, 0, 255);
    static const Color WHITESMOKE;
    // static const Color DARK = Color(76, 76, 76);
};
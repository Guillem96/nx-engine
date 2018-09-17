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
    static const Color WHITE;
    static const Color BLACK;
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color WHITESMOKE;
    static const Color DARK;
};
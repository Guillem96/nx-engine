#pragma once

#include <SDL2/SDL.h>

class Color
{
  private:
    SDL_Color m_color;

  public:
    constexpr Color() : m_color({0, 0, 0, 255})
    {
    }

    constexpr Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) : m_color({red, green, blue, alpha})
    {
    }

    constexpr Color(Uint8 red, Uint8 green, Uint8 blue) : m_color({red, green, blue, 255})
    {
    }

    const SDL_Color &get() const { return m_color; }
};

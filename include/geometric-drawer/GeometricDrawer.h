#pragma once

#include <SDL2/SDL.h>
#include <vector>

class GeometricDrawer
{
  private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    std::vector<Figure *> m_figureList;

  public:
    GeometricDrawer(SDL_Window *window, SDL_Renderer *renderer);
    ~GeometricDrawer();

    void init();

    void add(Figure *figure);

    void draw();

    void destroy();
};

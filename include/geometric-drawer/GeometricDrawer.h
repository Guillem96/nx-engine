#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "geometric-drawer/Figure.h"

/**
 * @brief Responsible to render Geometric Shapes (Figures)
 * 
 */
class GeometricDrawer
{
  private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    std::vector<Figure *> m_figureList;

  public:
    GeometricDrawer(SDL_Window *window, SDL_Renderer *renderer);
    ~GeometricDrawer();

    /**
     * @brief Initialize Geometric Drawer 
     * 
     */
    void init();

    /**
     * @brief Add a figure to the render queue
     * 
     * @param figure Figure to be rendered
     */
    void add(Figure *figure);

    /**
     * @brief Render all the figures present at render queueu
     * 
     */
    void draw();

    /**
     * @brief Clear environment of geometric drawer and deallocate all added figures 
     * 
     */
    void destroy();
};

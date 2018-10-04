#pragma once

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sprite-renderer/Sprite.h"

class SpriteRenderer
{
  private:
    std::vector<Sprite *> m_sprites;
    std::vector<SDL_Texture *> m_textures;

    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

  public:
    SpriteRenderer(SDL_Window *window, SDL_Renderer *renderer);
    ~SpriteRenderer();

    void init();
    void destroy();

    void addSprite(Sprite *sprite);
    void draw();
};

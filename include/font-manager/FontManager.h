#pragma once

#include <SDL2/SDL.h>

#include "screen-manager/GfxScreen.h"

#include "font-manager/Text.h"

class FontManager
{
  friend class GfxScreen;

  private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    std::vector<Text *> m_textList;

    bool init();

  public:
    FontManager(SDL_Window *window, SDL_Renderer *renderer);
    ~FontManager();

    // Add text in order to be rendered on the draw function
    // Once the texts are added FontManager will be the responsible of free them
    void addText(Text* t);

    void draw();

    // Deinitialize ttf_font and free all TextList
    void destroy();
};

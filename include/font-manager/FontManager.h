#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "font-manager/Text.h"

class FontManager
{
  private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    std::vector<Text *> m_textList;

    void generateTextPosition(Text *t);

  public:
    FontManager(SDL_Window *window, SDL_Renderer *renderer);
    ~FontManager();

    void init();

    // Add text in order to be rendered on the draw function
    // Once the texts are added FontManager will be the responsible of free them
    void addText(Text *t);

    void draw();

    // Deinitialize ttf_font and free all TextList
    void destroy();
};

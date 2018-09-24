#pragma once

#include <string>
#include <SDL2/SDL_ttf.h>

class Font
{
private:
    TTF_Font* m_font = nullptr;
public:
    Font(const std::string &path, int size);
    ~Font();

    TTF_Font* get();
};
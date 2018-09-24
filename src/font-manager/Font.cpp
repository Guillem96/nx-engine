#include "font-manager/Font.h"

Font::Font(const std::string &path, int size)
{
    m_font = TTF_OpenFont(path.c_str(), size);
    if(!m_font)
    {
        SDL_Quit();
    }
}

Font::~Font()
{
    free(m_font);
}

TTF_Font *Font::get()
{
    return m_font;
}
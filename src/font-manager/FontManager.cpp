#include "font-manager/FontManager.h"

FontManager::FontManager(SDL_Window *window, SDL_Renderer *renderer) : m_window(window), m_renderer(renderer)
{
}

FontManager::~FontManager()
{
}

void FontManager::init()
{
    if (TTF_Init() < 0)
        SDL_Quit();
}

void FontManager::addText(Text *t)
{
    m_textList.push_back(t);
}

void FontManager::draw()
{
    for (Text *t : m_textList)
    {
        TTF_Font *font = t->getFont()->get();
        SDL_Color color = t->getColor().get();

        int screenWidth;
        SDL_GetWindowSize(m_window, &screenWidth, NULL);

        SDL_Surface *surface = TTF_RenderText_Blended_Wrapped(font, t->getText().c_str(), color, screenWidth);
        SDL_SetSurfaceAlphaMod(surface, color.a);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
        SDL_FreeSurface(surface);

        SDL_Rect position;
        position.x = t->getPosition().x;
        position.y = t->getPosition().y;
        SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
        SDL_RenderCopy(m_renderer, texture, NULL, &position);
        SDL_DestroyTexture(texture);
    }
}

void FontManager::generateTextPosition(Text *t)
{
    if (t->getAlignmentFlags() == TextAlignFlags::FREE)
        return;

    int screenWidth, screenHeight;
    SDL_GetWindowSize(m_window, &screenWidth, &screenHeight);

    Vector2 dims = t->getTextDims();
    Vector2 textPos;

    // Horizontal alignment
    if (t->getAlignmentFlags() & TextAlignFlags::CENTER)
    {
        float screenCenter = screenWidth / 2.0f;
        textPos.x = screenCenter - dims.x / 2.0f;
    }
    else if (t->getAlignmentFlags() & TextAlignFlags::LEFT)
    {
        textPos.x = t->getPaddingLeft();
    }
    else if (t->getAlignmentFlags() & TextAlignFlags::RIGHT)
    {
        textPos.x = screenWidth - dims.x - t->getPaddingRight();
    }

    // Vertical alignment
    if (t->getAlignmentFlags() & TextAlignFlags::MIDDLE)
    {
        float screenCenter = screenHeight / 2.0f;
        textPos.y = screenCenter - dims.y / 2.0f;
    }
    else if (t->getAlignmentFlags() & TextAlignFlags::TOP)
    {
        textPos.y = t->getPaddingTop();
    }
    else if (t->getAlignmentFlags() & TextAlignFlags::BOTTOM)
    {
        textPos.y = screenHeight - dims.y - t->getPaddingBottom();
    }
    t->setPosition(textPos);
}

void FontManager::destroy()
{

    for (size_t i = 0; i < m_textList.size(); i++)
    {
        delete m_textList[i];
    }
    m_textList.clear();
}
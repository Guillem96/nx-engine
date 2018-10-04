#include "sprite-renderer/SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(SDL_Window *window, SDL_Renderer *renderer) : m_window(window), m_renderer(renderer)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::init()
{
    if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
        return;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        SDL_Quit();
}

void SpriteRenderer::destroy()
{
    for (size_t i = 0; i < m_sprites.size(); i++)
    {
        free(m_textures[i]);
        delete m_sprites[i];
    }
}

void SpriteRenderer::addSprite(Sprite *sprite)
{
    int w, h;
    SDL_Texture *img = IMG_LoadTexture(m_renderer, sprite->m_path.c_str());
    SDL_QueryTexture(img, NULL, NULL, &w, &h);
    sprite->m_size = Vector2((float)w, (float)h);

    m_sprites.push_back(sprite);
    m_textures.push_back(img);
}

void SpriteRenderer::draw()
{
    for (size_t i = 0; i < m_sprites.size(); i++)
    {
        SDL_Rect rect;
        rect.x = m_sprites[i]->getPosition().x;
        rect.y = m_sprites[i]->getPosition().y;
        rect.w = m_sprites[i]->getSize().x;
        rect.h = m_sprites[i]->getSize().y;

        SDL_RenderCopy(m_renderer, m_textures[i], NULL, &rect);
    }
}
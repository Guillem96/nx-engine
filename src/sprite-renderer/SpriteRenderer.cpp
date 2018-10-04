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
        generateSpritePosition(m_sprites[i]);

        SDL_Rect rect;
        rect.x = m_sprites[i]->getPosition().x;
        rect.y = m_sprites[i]->getPosition().y;
        rect.w = m_sprites[i]->getSize().x;
        rect.h = m_sprites[i]->getSize().y;

        SDL_RenderCopy(m_renderer, m_textures[i], NULL, &rect);
    }
}

void SpriteRenderer::generateSpritePosition(Sprite *sprite)
{
    if (sprite->getAlignmentFlags() == ScreenAlignFlags::FREE)
        return;

    int screenWidth, screenHeight;
    SDL_GetWindowSize(m_window, &screenWidth, &screenHeight);

    Vector2 dims = sprite->getSize();
    Vector2 spritePos = sprite->getPosition();

    // Horizontal alignment
    if (sprite->getAlignmentFlags() & ScreenAlignFlags::CENTER)
    {
        float screenCenter = screenWidth / 2.0f;
        spritePos.x = screenCenter - dims.x / 2.0f;
    }
    else if (sprite->getAlignmentFlags() & ScreenAlignFlags::LEFT)
    {
        spritePos.x = sprite->getPaddingLeft();
    }
    else if (sprite->getAlignmentFlags() & ScreenAlignFlags::RIGHT)
    {
        spritePos.x = screenWidth - dims.x - sprite->getPaddingRight();
    }

    // Vertical alignment
    if (sprite->getAlignmentFlags() & ScreenAlignFlags::MIDDLE)
    {
        float screenCenter = screenHeight / 2.0f;
        spritePos.y = screenCenter - dims.y / 2.0f;
    }
    else if (sprite->getAlignmentFlags() & ScreenAlignFlags::TOP)
    {
        spritePos.y = sprite->getPaddingTop();
    }
    else if (sprite->getAlignmentFlags() & ScreenAlignFlags::BOTTOM)
    {
        spritePos.y = screenHeight - dims.y - sprite->getPaddingBottom();
    }
    sprite->setPosition(spritePos);
}
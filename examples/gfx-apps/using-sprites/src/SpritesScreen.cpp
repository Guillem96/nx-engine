#include "SpritesScreen.h"

void SpritesScreen::build()
{
    // Create the InputManager component using a factory
    m_inputManager = m_screen->factory()->createInputManager();
    m_inputManager->init();

    // Create the InputManager component using a factory
    m_spriteRenderer = m_screen->factory()->createSpriteRenderer((GfxScreen *)m_screen);
    m_spriteRenderer->init();

    Sprite *hk = new Sprite("romfs:/img/latest.png", Vector2(), Vector2(0.25f), ScreenAlignFlags::BOTTOM | ScreenAlignFlags::LEFT);
    hk->setPaddingBottom(-20.0f);
    hk->setPaddingLeft(20.0f);

    Sprite *paleKing = new Sprite("romfs:/img/pale_king.png", Vector2(), Vector2(1.0f), ScreenAlignFlags::BOTTOM | ScreenAlignFlags::RIGHT);
    paleKing->setPaddingBottom(0.0f);
    paleKing->setPaddingRight(20.0f);

    // X position is important because only vertical alignment is set
    Sprite *grim = new Sprite("romfs:/img/grim_son.png", Vector2(400.0f, .0f), Vector2(1.0f), ScreenAlignFlags::MIDDLE);
    Sprite *soul = new Sprite("romfs:/img/soul.png", Vector2(600.0f, .0f), Vector2(1.0f), ScreenAlignFlags::MIDDLE);

    m_spriteRenderer->addSprite(hk);
    m_spriteRenderer->addSprite(paleKing);
    m_spriteRenderer->addSprite(grim);
    m_spriteRenderer->addSprite(soul);
}

void SpritesScreen::destroy()
{
    m_inputManager->destroy();
    delete m_inputManager;

    m_spriteRenderer->destroy();
    delete m_spriteRenderer;
}

void SpritesScreen::update()
{
    m_inputManager->update();

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::EXIT_APPLICATION;
    }
}

void SpritesScreen::draw()
{
    m_spriteRenderer->draw();
}
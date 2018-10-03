#include "DeveloperScreen.h"
#include "ScreenIndex.h"

DeveloperScreen::DeveloperScreen()
{
}

DeveloperScreen::~DeveloperScreen()
{
}

int DeveloperScreen::getNextScreenIndex() const
{
    return SCREEN_INDEX_NO_SCREEN;
}

int DeveloperScreen::getPreviousScreenIndex() const
{
    return MAIN_MENU_INDEX;
}

void DeveloperScreen::build()
{
    // Create the InputManager component using a factory
    m_inputManager = m_screen->factory()->createInputManager();
    m_inputManager->init();

    // Create the InputManager component using a factory
    m_fontManager = m_screen->factory()->createFontManager((GfxScreen *)m_screen);
    m_fontManager->init();

    m_font = new Font("romfs:/Raleway-Regular.ttf", 20);
    m_msgFont = new Font("romfs:/Impact_Label.ttf", 80);

    m_message = new Text("Guillem96", m_msgFont, Vector2(), COLORS[0], TextAlignFlags::MIDDLE | TextAlignFlags::CENTER);
    m_fontManager->addText(m_message);

    // Build controls
    Text *controls = new Text("Press B to go back, < or > to change text colors", m_font, Vector2(), Colors::RED, TextAlignFlags::BOTTOM | TextAlignFlags::CENTER);
    m_fontManager->addText(controls);
}

void DeveloperScreen::destroy()
{
    delete m_font;
    delete m_msgFont;

    m_inputManager->destroy();
    delete m_inputManager;

    m_fontManager->destroy();
    delete m_fontManager;
}

void DeveloperScreen::onEntry()
{
}

void DeveloperScreen::onExit()
{
    m_inputManager->clear(); // Clear events to avoid strange scenarions (recommended)
}

void DeveloperScreen::update()
{
    m_inputManager->update();

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_DLEFT) || m_inputManager->isKeyPressed(JoyconButtons::J_KEY_LSTICK_LEFT))
    {
        if (m_color != 0)
        {
            m_color--;
            m_message->setColor(COLORS[m_color]);
        }
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_DRIGHT) || m_inputManager->isKeyPressed(JoyconButtons::J_KEY_LSTICK_RIGHT))
    {
        if (m_color != NUM_COLORS - 1)
        {
            m_color++;
            m_message->setColor(COLORS[m_color]);
        }
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::CHANGE_PREVIOUS;
    }
}

void DeveloperScreen::draw()
{
    m_fontManager->draw();
}
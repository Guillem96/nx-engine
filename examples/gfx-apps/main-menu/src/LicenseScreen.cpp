#include "LicenseScreen.h"
#include "ScreenIndex.h"

LicenseScreen::LicenseScreen()
{
}

LicenseScreen::~LicenseScreen()
{
}

int LicenseScreen::getNextScreenIndex() const
{
    return SCREEN_INDEX_NO_SCREEN;
}

int LicenseScreen::getPreviousScreenIndex() const
{
    return MAIN_MENU_INDEX;
}

void LicenseScreen::build()
{
    // Create the InputManager component using a factory
    m_inputManager = m_screen->factory()->createInputManager();
    m_inputManager->init();

    // Create the InputManager component using a factory
    m_fontManager = m_screen->factory()->createFontManager((GfxScreen *)m_screen);
    m_fontManager->init();

    m_font = new Font("romfs:/Raleway-Regular.ttf", 20);
    m_msgFont = new Font("romfs:/Impact_Label.ttf", 80);

    m_message = new Text("GPL v3.0", m_msgFont, Vector2(), COLORS[0], ScreenAlignFlags::MIDDLE | ScreenAlignFlags::CENTER);
    m_fontManager->addText(m_message);

    // Build controls
    Text *controls = new Text("Press B to go back, < or > to change text colors", m_font, Vector2(), Colors::RED, ScreenAlignFlags::BOTTOM | ScreenAlignFlags::CENTER);
    m_fontManager->addText(controls);
}

void LicenseScreen::destroy()
{
    delete m_font;
    delete m_msgFont;

    m_inputManager->destroy();
    delete m_inputManager;

    m_fontManager->destroy();
    delete m_fontManager;
}

void LicenseScreen::onEntry()
{
}

void LicenseScreen::onExit()
{
    m_inputManager->clear(); // Clear events to avoid strange scenarions (recommended)
}

void LicenseScreen::update()
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

void LicenseScreen::draw()
{
    m_fontManager->draw();
}
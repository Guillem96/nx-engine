#include "DisplayMessageScreen.h"

DisplayMessageScreen::DisplayMessageScreen(std::string message) : m_message(message)
{
}

DisplayMessageScreen::~DisplayMessageScreen()
{
}

int DisplayMessageScreen::getNextScreenIndex() const
{
    if(m_screenIndex == 2)
        return SCREEN_INDEX_NO_SCREEN;

    return m_screenIndex + 1;
}

int DisplayMessageScreen::getPreviousScreenIndex() const
{
    if(m_screenIndex == 0)
        return SCREEN_INDEX_NO_SCREEN;
    
    return m_screenIndex - 1;
}

void DisplayMessageScreen::build()
{
}

void DisplayMessageScreen::destroy()
{
}

void DisplayMessageScreen::onEntry()
{
    printf("%s\n", m_message.c_str());
}

void DisplayMessageScreen::onExit()
{
    consoleClear();
}

void DisplayMessageScreen::update()
{
    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DRIGHT))
    {
        m_currentState = ScreenState::CHANGE_NEXT;
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DLEFT))
    {
        m_currentState = ScreenState::CHANGE_PREVIOUS;
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_PLUS))
    {
        m_currentState = ScreenState::EXIT_APPLICATION;
    }
}

void DisplayMessageScreen::draw()
{
}
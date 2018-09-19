#include "DisplayMessageScreen.h"

DisplayMessageScreen::DisplayMessageScreen(std::string message, int maxScreens) : m_message(message), m_maxScreens(maxScreens)
{
}

DisplayMessageScreen::~DisplayMessageScreen()
{
}

int DisplayMessageScreen::getNextScreenIndex() const
{
    if(m_screenIndex == m_maxScreens - 1)
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
    // Info extracted from: https://github.com/switchbrew/switch-examples/
    // Move the cursor to row 16 and column 20 and then prints the message
    // To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
    // the row and column where you want your cursor to move
    printf("\x1b[2;37HScreen %d\n", m_screenIndex + 1);

    printf("\x1b[20;30H%s\n", m_message.c_str());

    printf("\x1b[45;15HPress <- -> to navigate between screens, or + to exit.\n");
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
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
}

void DeveloperScreen::destroy()
{
}

void DeveloperScreen::onEntry()
{
}

void DeveloperScreen::onExit()
{
    consoleClear();
}

void DeveloperScreen::update()
{
    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DLEFT) || m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_LEFT))
    {
        if (m_color != 0)
            m_color--;
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DRIGHT) || m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_RIGHT))
    {
        if (m_color != 7) // MAX COLORS ARE 8
            m_color++;
    }
    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::CHANGE_PREVIOUS;
    }
}

void DeveloperScreen::draw()
{
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[15;17H   _____       _ _ _               ___    __  " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[16;17H  / ____|     (_) | |             / _ \\  / /  " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[17;17H | |  __ _   _ _| | | ___ _ __ __| (_) |/ /_  " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[18;17H | | |_ | | | | | | |/ _ \\ '_ ` _ \\__, | '_ \\ " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[19;17H | |__| | |_| | | | |  __/ | | | | |/ /| (_) |" CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[20;17H  \\_____|\\__,_|_|_|_|\\___|_| |_| |_/_/  \\___/ " CONSOLE_ESC(0m), m_color + 30);
    printf("\x1b[45;13HPress LEFT RIGHT to change text color, or B to go back.");
}
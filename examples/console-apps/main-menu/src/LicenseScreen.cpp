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
}

void LicenseScreen::destroy()
{
}

void LicenseScreen::onEntry()
{
    printf("\x1b[45;13HPress LEFT RIGHT to change text color, or B to go back.");
}

void LicenseScreen::onExit()
{
    consoleClear();
}

void LicenseScreen::update()
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

void LicenseScreen::draw()
{
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[15;17H           _  (`-')               (`-')         " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[16;17H    .->    \\-.(OO )   <-.        _(OO )         " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[17;17H ,---(`-') _.'    \\ ,--. )  ,--.(_/,-.\\ .----.  " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[18;17H'  .-(OO )(_...--'' |  (`-')\\   \\ / (_/\\_.-,  | " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[19;17H|  | .-, \\|  |_.' | |  |OO ) \\   /   /   |_  <  " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[20;17H|  | '.(_/|  .___.'(|  '__ |_ \\     /_).-. \\  | " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[21;17H|  '-'  | |  |      |     |'\\-'\\   /   \\ `-'  / " CONSOLE_ESC(0m), m_color + 30);
    printf(CONSOLE_ESC(%1$d;1m) "\x1b[22;17H `-----'  `--'      `-----'     `-'     `---''  " CONSOLE_ESC(0m), m_color + 30);
}
#include "MenuScreen.h"
#include "ScreenIndex.h"

MenuScreen::MenuScreen()
{
    m_menuEntries["Developer Info"] = DEVELOPER_SCREEN_INDEX;
    m_menuEntries["License Info"] = LICENSE_SCREEN_INDEX;
}

MenuScreen::~MenuScreen()
{
}

int MenuScreen::getNextScreenIndex() const
{
    return SCREEN_INDEX_NO_SCREEN;
}

int MenuScreen::getPreviousScreenIndex() const
{
    return SCREEN_INDEX_NO_SCREEN;
}

void MenuScreen::build()
{
}

void MenuScreen::destroy()
{
}

void MenuScreen::onEntry()
{
    printMenu();
}

void MenuScreen::onExit()
{
    consoleClear();
}

void MenuScreen::update()
{
    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_A))
    {
        m_currentState = ScreenState::CHANGE_NEXT;
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::EXIT_APPLICATION;
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DDOWN) || m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_DOWN))
    {
        if(m_selectedOption != (int)m_menuEntries.size() - 1)
            m_selectedOption++;
            
        printMenu();
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DUP) || m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_UP))
    {
        if(m_selectedOption != 0)
            m_selectedOption--; 

        printMenu();
    }
}

void MenuScreen::printMenu()
{
    consoleClear();
    
    printf("\x1b[2;37HMAIN MENU\n");

    int idx = 0;
    int startRow = 15; 
    for (auto& it: m_menuEntries)
    {
        if (idx == m_selectedOption)
            printf("\x1b[%d;10H-> %s\n", (startRow + idx), it.first.c_str());
        else
            printf("\x1b[%d;10H   %s\n", (startRow + idx), it.first.c_str());

        idx++;
    }

    printf("\x1b[45;15HPress UP DOWN to navigate between entries, or B to exit.\n");

}

void MenuScreen::draw()
{
}
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
    int nextIndex = getEntryIndex();
    return nextIndex;
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
    m_menuEntries.clear();
}

void MenuScreen::onEntry()
{
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
    }

    if (m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_DUP) || m_screen->eventManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_UP))
    {
        if(m_selectedOption != 0)
            m_selectedOption--; 
    }
}

void MenuScreen::printMenu()
{
  
    printf("\x1b[2;37HMAIN MENU");

    int idx = 0;
    int startRow = 15; 
    for (auto& it: m_menuEntries)
    {
        if (idx == m_selectedOption)
            printf("\x1b[%d;10H-> %s", (startRow + idx), it.first.c_str());
        else
            printf("\x1b[%d;10H   %s", (startRow + idx), it.first.c_str());

        idx++;
    }

    printf("\x1b[45;15HPress UP DOWN to navigate between entries, or B to exit.");
}

void MenuScreen::draw()
{
    printMenu();
}

int MenuScreen::getEntryIndex() const 
{
    int idx = 0;
    for (auto& it: m_menuEntries)
    {
        if(idx == m_selectedOption)
            return it.second;
        
        idx++;
    }
    return SCREEN_INDEX_NO_SCREEN;
}
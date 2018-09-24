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
    m_font = new Font("romfs:/Raleway-Regular.ttf", 30);
    for (auto& it: m_menuEntries)
    {
        Text *t = new Text(it.first, m_font, Vector2(200.0f, 100.0f), Colors::BLACK);
        m_textEntries.push_back(t);
        
        m_screen->fontManager()->addText(t);
    }
}

void MenuScreen::destroy()
{
    m_textEntries.clear();
    m_menuEntries.clear();
}

void MenuScreen::onEntry()
{
}

void MenuScreen::onExit()
{
}

void MenuScreen::update()
{
    if (m_screen->inputManager()->isKeyPressed(JoyconButtons::J_KEY_A))
    {
        m_currentState = ScreenState::CHANGE_NEXT;
    }

    if (m_screen->inputManager()->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::EXIT_APPLICATION;
    }

    if (m_screen->inputManager()->isKeyPressed(JoyconButtons::J_KEY_DDOWN) || m_screen->inputManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_DOWN))
    {
        if(m_selectedOption != (int)m_menuEntries.size() - 1)
            m_selectedOption++;
    }

    if (m_screen->inputManager()->isKeyPressed(JoyconButtons::J_KEY_DUP) || m_screen->inputManager()->isKeyPressed(JoyconButtons::J_KEY_LSTICK_UP))
    {
        if(m_selectedOption != 0)
            m_selectedOption--; 
    }

    m_textEntries[m_selectedOption]->setColor(Colors::BLUE);
}

void MenuScreen::draw()
{
    m_screen->fontManager()->draw();
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
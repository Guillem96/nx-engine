#include "screen-manager/ScreenList.h"

#include "screen-manager/IMainScreen.h"
#include "screen-manager/IScreen.h"

ScreenList::ScreenList(IMainScreen *screen) : m_screen(screen)
{
}

ScreenList::~ScreenList()
{
    destroy();
}

IScreen *ScreenList::moveNext()
{
    IScreen *currentScreen = getCurrent();

    if (currentScreen->getNextScreenIndex() != SCREEN_INDEX_NO_SCREEN)
        m_currentScreenIndex = currentScreen->getNextScreenIndex();

    return getCurrent();
}

IScreen *ScreenList::movePrevious()
{
    IScreen *currentScreen = getCurrent();

    if (currentScreen->getPreviousScreenIndex() != SCREEN_INDEX_NO_SCREEN)
        m_currentScreenIndex = currentScreen->getPreviousScreenIndex();

    return getCurrent();
}

void ScreenList::setScreen(int nextScreen)
{
    m_currentScreenIndex = nextScreen;
}

void ScreenList::addScreen(IScreen *newScreen)
{
    newScreen->m_screenIndex = m_screens.size();
    m_screens.push_back(newScreen);
    newScreen->build();
    newScreen->setParentScreen(m_screen);
}

void ScreenList::destroy()
{
    for (size_t i = 0; i < m_screens.size(); i++)
        m_screens[i]->destroy();

    m_screens.clear();
    m_currentScreenIndex = SCREEN_INDEX_NO_SCREEN;
}

IScreen *ScreenList::getCurrent()
{
    if (m_currentScreenIndex == SCREEN_INDEX_NO_SCREEN)
        return nullptr;
    return m_screens[m_currentScreenIndex];
}

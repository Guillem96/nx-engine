#include "screen-manager/IMainScreen.h"

void IMainScreen::draw()
{
    if (m_running && m_currentScreen && m_currentScreen->getState() == ScreenState::RUNNING)
        m_currentScreen->draw();
}

void IMainScreen::update()
{
    if (m_currentScreen)
    {
        switch (m_currentScreen->getState())
        {
        case ScreenState::RUNNING:
            m_currentScreen->update();
            break;
        case ScreenState::CHANGE_NEXT:
            m_currentScreen->onExit();
            m_currentScreen = m_screenList->moveNext();
            m_currentScreen->m_currentState = ScreenState::NONE;
            if (m_currentScreen)
            {
                m_currentScreen->setRunning();
                m_currentScreen->onEntry();
            }
            break;
        case ScreenState::CHANGE_PREVIOUS:
            m_currentScreen->onExit();
            m_currentScreen = m_screenList->movePrevious();
            m_currentScreen->m_currentState = ScreenState::NONE;
            if (m_currentScreen)
            {
                m_currentScreen->setRunning();
                m_currentScreen->onEntry();
            }
            break;
        case ScreenState::EXIT_APPLICATION:
            exitApp();
            break;
        default:
            break;
        }
    }
    else
    {
        exitApp();
    }
}

InputManager *IMainScreen::inputManager()
{
    return m_inputManager;
}

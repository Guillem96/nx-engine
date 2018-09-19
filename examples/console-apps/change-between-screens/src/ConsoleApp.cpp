#include "ConsoleApp.h"

ConsoleApp::ConsoleApp(std::vector<std::string> messages) : m_messages(messages) 
{
}

ConsoleApp::~ConsoleApp()
{
}

void ConsoleApp::onInit()
{
    for(size_t i = 0; i < m_messages.size(); i++)
    {
        DisplayMessageScreen* dms = new DisplayMessageScreen(m_messages[i], (int)m_messages.size());
        m_displayScreens.push_back(dms);
    }
}

void ConsoleApp::addScreens()
{
    for(size_t i = 0; i < m_displayScreens.size(); i++)
        m_screenList->addScreen(m_displayScreens[i]);

    m_screenList->setScreen(0);
}

void ConsoleApp::onExit()
{
    m_displayScreens.clear(); // Screen list will take care of free memory of each screen
    m_messages.clear();
}
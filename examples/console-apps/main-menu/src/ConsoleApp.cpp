#include "ConsoleApp.h"

#include "ScreenIndex.h"

ConsoleApp::ConsoleApp()
{
}

ConsoleApp::~ConsoleApp()
{
}

void ConsoleApp::onInit()
{
}

void ConsoleApp::addScreens()
{
    m_screenList->addScreen(new MenuScreen());
    m_screenList->addScreen(new LicenseScreen());
    m_screenList->addScreen(new DeveloperScreen());

    m_screenList->setScreen(MAIN_MENU_INDEX);
}

void ConsoleApp::onExit()
{
}
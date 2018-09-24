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
    m_screenList->addScreen(new MenuScreen());      // SCREEN INDEX = 0
    m_screenList->addScreen(new LicenseScreen());   // SCREEN INDEX = 1
    m_screenList->addScreen(new DeveloperScreen()); // SCREEN INDEX = 2

    m_screenList->setScreen(MAIN_MENU_INDEX);
}

void ConsoleApp::onExit()
{
}
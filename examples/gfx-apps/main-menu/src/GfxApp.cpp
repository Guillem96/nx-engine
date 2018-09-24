#include "GfxApp.h"

#include "ScreenIndex.h"

GfxApp::GfxApp()
{
}

GfxApp::~GfxApp()
{
}

void GfxApp::onInit()
{
}

void GfxApp::addScreens()
{
    m_screenList->addScreen(new MenuScreen());      // SCREEN INDEX = 0
    // m_screenList->addScreen(new LicenseScreen());   // SCREEN INDEX = 1
    // m_screenList->addScreen(new DeveloperScreen()); // SCREEN INDEX = 2

    m_screenList->setScreen(MAIN_MENU_INDEX);
}

void GfxApp::onExit()
{
}
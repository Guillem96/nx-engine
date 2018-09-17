#pragma once

#include <nx-engine.h>

#include "IdentityScreen.h"

// Will contain all the screens
// Will call the current screen update and draw methods each frame
class ScreenController : public GfxScreen
{
  private:
    IdentityScreen* m_identityScreen = nullptr;

  public:
    ScreenController() : GfxScreen() {}
    ScreenController(int windowHeight, int windowWidth) : GfxScreen(windowHeight, windowWidth) {}
    ScreenController(const Color &color, int windowHeight, int windowWidth) : GfxScreen(color, windowHeight, windowWidth) {}
    ~ScreenController() {}

    virtual void onInit() override 
    {
        // *** Initialize any class member of the screen controller ***
        m_identityScreen = new IdentityScreen();      // Create the screen
    }

    virtual void addScreens() override
    {
        m_screenList->addScreen(m_identityScreen);                   // Add the screen to screen controller
        m_screenList->setScreen(m_identityScreen->getScreenIndex()); // set the identity screen as the current screen using its index

        // *** More screens can be added down here ***
    }

    virtual void onExit() override 
    {
        delete m_identityScreen;

        // *** Destroy all the class members and screens ***
    }

};
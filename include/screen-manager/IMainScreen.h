#pragma once

#include "screen-manager/ScreenList.h"
#include "screen-manager/IScreen.h"

#include "event-manager/EventManager.h"

class IMainScreen
{
  public:
    // Runs and initializes the game
    virtual void run() = 0;
    // Exits the app
    virtual void exit() = 0;

  protected:
    IMainScreen()
    {
        m_screenList = new ScreenList(this);
    }
    virtual ~IMainScreen() {}

    ScreenList *m_screenList = nullptr;
    IScreen *m_currentScreen = nullptr;

    // Screen components
    EventManager *m_eventManager = nullptr;

    // Called on initialization
    virtual void onInit() = 0;
    // For adding all screens
    virtual void addScreens() = 0;
    // Called when exiting
    virtual void onExit() = 0;

    EventManager *eventManager();

    void draw();
    void update();
};
#pragma once

#include <memory>

#include "ScreenList.h"

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
        m_screenList = std::make_unique<ScreenList>(this);
    }

    virtual ~IMainScreen();

    // Called on initialization
    virtual void onInit() = 0;
    // For adding all screens
    virtual void addScreens() = 0;
    // Called when exiting
    virtual void onExit() = 0;

  private:
    void draw();
    void update();
    std::unique_ptr<ScreenList> m_screenList;
};
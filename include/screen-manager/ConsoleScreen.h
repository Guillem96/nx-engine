#pragma once

#include "screen-manager/IMainScreen.h"

#include <switch.h>

#include "event-manager/ConsoleEventManager.h"

class ConsoleScreen : public IMainScreen
{
  private:
    bool init();
    bool initSystems();

  public:
    ConsoleScreen();
    virtual ~ConsoleScreen() {}

  protected:
    virtual void onInit() = 0;
    virtual void addScreens() = 0;
    virtual void onExit() = 0;

  public:
    virtual void run() override;
    virtual void exitApp() override;
};
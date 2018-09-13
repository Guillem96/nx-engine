#pragma once

#include "IMainScreen.h"

#include <switch.h>

class ConsoleScreen : public IMainScreen
{
  private:
    bool m_running = false;

    bool init();
    bool initSystems();

  public:
    ConsoleScreen();
    virtual ~ConsoleScreen();

  protected:
    virtual void onInit() = 0;
    virtual void addScreens() = 0;
    virtual void onExit() = 0;

  public:
    virtual void run() override;
    virtual void exit() override;
};
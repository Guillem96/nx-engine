#pragma once

#include <switch.h>

#include <map>

#include "EventManager.h"

class ConsoleEventManager : public EventManager
{
  private:
    const int PAD_BUTTONS = 32;

  public:
    ConsoleEventManager() {}
    ~ConsoleEventManager() {}

    virtual void init() override;
    virtual void update() override;
    virtual void destroy() override;
};
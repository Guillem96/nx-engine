#pragma once

#include <switch.h>

#include <map>

#include "InputManager.h"

class ConsoleInputManager : public InputManager
{
  private:
    const int PAD_BUTTONS = 32;

  public:
    ConsoleInputManager() {}
    ~ConsoleInputManager() {}

    virtual void init() override;
    virtual void update() override;
    virtual void destroy() override;
};
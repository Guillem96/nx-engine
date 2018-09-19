#pragma once

#include <nx-engine.h>

#include <vector>
#include <string>

#include "MenuScreen.h"

// Recieves a vector of strings and for each string generates a screen to print it
class ConsoleApp : public ConsoleScreen
{
  public:
    ConsoleApp();
    ~ConsoleApp();

    virtual void onInit() override;
    virtual void addScreens() override;
    virtual void onExit() override;
};
#pragma once

#include <nx-engine.h>

#include <vector>
#include <string>

#include "DisplayMessageScreen.h"

// Recieves a vector of strings and for each string generates a screen to print it
class ConsoleApp : public ConsoleScreen
{
  private:
    std::vector<std::string> m_messages;
    std::vector<IScreen*> m_displayScreens;

  public:
    ConsoleApp(std::vector<std::string> messages);
    ~ConsoleApp();

    virtual void onInit() override;
    virtual void addScreens() override;
    virtual void onExit() override;
};
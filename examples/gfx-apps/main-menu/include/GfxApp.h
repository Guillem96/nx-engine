#pragma once

#include <nx-engine.h>

#include <vector>
#include <string>

#include "MenuScreen.h"
// #include "DeveloperScreen.h"
// #include "LicenseScreen.h"

// Recieves a vector of strings and for each string generates a screen to print it
class GfxApp : public GfxScreen
{
  public:
    GfxApp();
    ~GfxApp();

    virtual void onInit() override;
    virtual void addScreens() override;
    virtual void onExit() override;
};
#pragma once

#include <nx-engine.h>

#include <vector>
#include <string>

#include "PolygonsScreen.h"

// Recieves a vector of strings and for each string generates a screen to print it
class GfxApp : public GfxScreen
{
  public:
    GfxApp(const Color &bgColor);
    ~GfxApp();

    virtual void onInit() override;
    virtual void addScreens() override;
    virtual void onExit() override;
};
#pragma once

#include "input-manager/InputManager.h"
#include "font-manager/FontManager.h"

class GfxScreen;

class ComponentFactory
{
  public:
    virtual ~ComponentFactory() {}

    virtual InputManager *createInputManager() = 0;
    virtual FontManager *createFontManager(GfxScreen *screen) = 0;
};
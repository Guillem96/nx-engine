#pragma once

#include "common/ComponentFactory.h"
#include "input-manager/ConsoleInputManager.h"

class ConsoleComponentFactory : public ComponentFactory
{
  public:
    virtual InputManager *createInputManager() override
    {
        return new ConsoleInputManager();
    }

    virtual FontManager *createFontManager(GfxScreen* screen) override 
    {
        return NULL;
    }
};

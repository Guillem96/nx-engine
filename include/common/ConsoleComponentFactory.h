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

    virtual FontManager *createFontManager(SDL_Window *window, SDL_Renderer *renderer) override 
    {
        return NULL;
    }
};

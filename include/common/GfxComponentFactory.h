#pragma once

#include "common/ComponentFactory.h"
#include "input-manager/GfxInputManager.h"

class GfxComponentFactory : public ComponentFactory
{
  public:
    virtual InputManager *createInputManager() override
    {
        return new GfxInputManager();
    }

    virtual FontManager *createFontManager(SDL_Window *window, SDL_Renderer *renderer) override 
    {
        return NULL;
    }
};

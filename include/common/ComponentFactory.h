#pragma once

#include "font-manager/FontManager.h"

class ComponentFactory
{
  public:
    virtual ~ComponentFactory() {}
    
    virtual InputManager *createInputManager() = 0;
    virtual FontManager *createFontManager(SDL_Window *window, SDL_Renderer *renderer) = 0;
};
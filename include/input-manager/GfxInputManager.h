
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include "input-manager/InputManager.h"

class GfxInputManager : public InputManager
{
  public:
    GfxInputManager() {}
    ~GfxInputManager() {}

    virtual void init() override;
    virtual void update() override;
    virtual void destroy() override;
};
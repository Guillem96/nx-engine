
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include "event-manager/EventManager.h"

class GfxEventManager : public EventManager
{
  public:
    GfxEventManager() {}
    ~GfxEventManager() {}

    virtual void init() override;
    virtual void update() override;
    virtual void destroy() override;
};
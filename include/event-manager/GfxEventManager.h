
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include "event-manager/EventManager.h"

class GfxEventManager : public EventManager
{
  public:
    GfxEventManager() {}
    ~GfxEventManager() {}

    void init() override;
    void update() override;
    void destroy() override;
};
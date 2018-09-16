
#pragma once

#include <SDL2/SDL.h>

#include "EventManager.h"

class GfxEventManager : public EventManager
{
  public:
    GfxEventManager();
    ~GfxEventManager();

    virtual void init() override;
    virtual void update() override;
    virtual void destroy() override;
};
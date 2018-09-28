#pragma once

#include "screen-manager/GfxScreen.h"

#include "common/ComponentFactory.h"
#include "input-manager/GfxInputManager.h"

class GfxComponentFactory : public ComponentFactory
{
  public:
    virtual InputManager *createInputManager() override
    {
        return new GfxInputManager();
    }

    virtual FontManager *createFontManager(GfxScreen* screen) override 
    {
        return new FontManager(screen->m_window, screen->m_renderer);
    }
};

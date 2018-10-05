#pragma once

#include "common/ComponentFactory.h"
#include "input-manager/GfxInputManager.h"

class GfxComponentFactory : public ComponentFactory
{
  public:
    virtual InputManager *createInputManager() override;
    virtual FontManager *createFontManager(GfxScreen *screen) override;
    virtual SpriteRenderer *createSpriteRenderer(GfxScreen *screen) override;
};

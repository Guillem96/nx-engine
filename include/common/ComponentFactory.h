#pragma once

#include "input-manager/InputManager.h"
#include "font-manager/FontManager.h"
#include "sprite-renderer/SpriteRenderer.h"
#include "geometric-Drawer/GeometricDrawer.h"

class GfxScreen;

class ComponentFactory
{
  public:
    virtual ~ComponentFactory() {}

    virtual InputManager *createInputManager() = 0;
    virtual FontManager *createFontManager(GfxScreen *screen) = 0;
    virtual SpriteRenderer *createSpriteRenderer(GfxScreen *screen) = 0;
    virtual GeometricDrawer *createGeometricDrawer(GfxScreen *screen) = 0;
};
#include "common/GfxComponentFactory.h"
#include "screen-manager/GfxScreen.h"

InputManager *GfxComponentFactory::createInputManager()
{
    return new GfxInputManager();
}

FontManager *GfxComponentFactory::createFontManager(GfxScreen *screen)
{
    return new FontManager(screen->getSDLWindow(), screen->getSDLRenderer());
}

SpriteRenderer *GfxComponentFactory::createSpriteRenderer(GfxScreen *screen)
{
    return new SpriteRenderer(screen->getSDLWindow(), screen->getSDLRenderer());
}

GeometricDrawer *GfxComponentFactory::createGeometricDrawer(GfxScreen *screen)
{
    return new GeometricDrawer(screen->getSDLWindow(), screen->getSDLRenderer());
}

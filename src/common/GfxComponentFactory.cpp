#include "common/GfxComponentFactory.h"
#include "screen-manager/GfxScreen.h"

InputManager *GfxComponentFactory::createInputManager()
{
    return new GfxInputManager();
}

FontManager *GfxComponentFactorycreateFontManager(GfxScreen *screen)
{
    return new FontManager(screen->getSDLWindow(), screen->getSDLRenderer());
}
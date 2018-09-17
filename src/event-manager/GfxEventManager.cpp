#include "event-manager/GfxEventManager.h"

void GfxEventManager::init()
{

    if (SDL_Init(SDL_INIT_JOYSTICK))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't init joycons: %s", SDL_GetError());
        SDL_Quit();
    }

    // Init joycons
    for (int i = 0; i < 2; i++)
    {
        if (SDL_JoystickOpen(i) == NULL)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_JoystickOpen: %s\n", SDL_GetError());
            SDL_Quit();
        }
    }
}

void GfxEventManager::update()
{
    EventManager::update();
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_JOYBUTTONDOWN:
            pressKey(event.jbutton.button);
            break;
        case SDL_JOYBUTTONUP:
            releaseKey(event.jbutton.button);
            break;
        }
    }
}

void GfxEventManager::destroy()
{
}

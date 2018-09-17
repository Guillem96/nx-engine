#include "event-manager/GfxEventManager.h"

void GfxEventManager::init()
{

    if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_EVENTS))
    {
        printf("Error init joycin.");
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't init joycons: %s", SDL_GetError());
        SDL_Quit();
    }

    // Init joycons
    for (int i = 0; i < 2; i++)
    {
        if (SDL_JoystickOpen(i) == NULL)
        {
            printf("Error init joycin %d.", i);
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
        case SDL_JOYAXISMOTION:
            printf("Joystick %d axis %d value: %d\n",
                   event.jaxis.which,
                   event.jaxis.axis, event.jaxis.value);
            break;
        case SDL_JOYBUTTONDOWN:
            printf("Joystick %d button %d down\n",
                   event.jbutton.which, event.jbutton.button);
            pressKey(event.jbutton.button);
            break;
        case SDL_KEYDOWN:
            printf("Keydown %d button %d down\n",
                   event.jbutton.which, event.jbutton.button);
            pressKey(event.jbutton.button);
            break;
        case SDL_JOYBUTTONUP:
            releaseKey(event.jbutton.button);
            break;
        case SDL_QUIT:
            printf("Quiting application\n");
            break;
        }
    }
}

void GfxEventManager::destroy()
{
}

#include "input-manager/GfxInputManager.h"

void GfxInputManager::init()
{
    if (SDL_WasInit(SDL_INIT_JOYSTICK) != 0)
        return;

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

void GfxInputManager::update()
{
    InputManager::update();
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
        case SDL_FINGERDOWN:
            m_touchCords = new Vector2(event.tfinger.x, event.tfinger.y);
            break;
        case SDL_FINGERUP:
            delete m_touchCords;
            m_touchCords = nullptr;
            break;
        }
    }
}

void GfxInputManager::destroy()
{
}

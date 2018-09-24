#include "input-manager/ConsoleInputManager.h"

void ConsoleInputManager::init()
{
}

void ConsoleInputManager::update()
{
    InputManager::update();

    hidScanInput();

    u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    u64 kUp = hidKeysUp(CONTROLLER_P1_AUTO);

    for (int i = 0; i < PAD_BUTTONS; i++)
    {
        if (kDown & BIT(i))
        {
            pressKey(i);
        }

        if (kUp & BIT(i))
        {
            releaseKey(i);
        }
    }
}

void ConsoleInputManager::destroy()
{
}
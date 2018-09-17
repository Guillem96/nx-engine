#include "event-manager/ConsoleEventManager.h"

void ConsoleEventManager::init()
{
}

void ConsoleEventManager::update()
{
    hidScanInput();

    u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    u64 kUp = hidKeysUp(CONTROLLER_P1_AUTO);
    // Key down
    for (int i = 0; i < PAD_BUTTONS; i++)
    {
        if (kDown & PAD[i])
            pressKey(i);

        if (kUp & PAD[i])
            releaseKey(i);
    }
}

void ConsoleEventManager::destroy()
{
}
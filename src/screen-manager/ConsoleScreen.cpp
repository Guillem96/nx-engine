#include "screen-manager/ConsoleScreen.h"

#include "exceptions/NxEngineException.h"

ConsoleScreen::ConsoleScreen()
{
}

void ConsoleScreen::run()
{
    if (init())
    {
        while (m_running)
        {
            hidScanInput();

            update();
            draw();

            gfxFlushBuffers();
            gfxSwapBuffers();
        }
    }
}

bool ConsoleScreen::init()
{
    if (!initSystems())
    {
        // throw NxEngineException("Error initializing Nintendo Switch console systems");
        return false;
    }

    m_running = true;

    onInit();
    addScreens();

    m_currentScreen = m_screenList->getCurrent();
    m_currentScreen->onEntry();
    m_currentScreen->setRunning();

    return true;
}

bool ConsoleScreen::initSystems()
{
    Result rc = romfsInit();
    if (rc)
    {

        // throw NxEngineException("Error initializing RomFs");
        return false;
    }

    consoleInit(NULL);

    return true;
}

void ConsoleScreen::exit()
{
    m_running = false;

    onExit();

    m_currentScreen->onExit();
    m_screenList->destroy();

    gfxExit();

    romfsExit();

    delete m_screenList;
}
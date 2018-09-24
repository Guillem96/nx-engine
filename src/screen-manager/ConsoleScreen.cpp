#include "screen-manager/ConsoleScreen.h"

#include "exceptions/NxEngineException.h"

#include <stdlib.h>

ConsoleScreen::ConsoleScreen()
{
}

void ConsoleScreen::run()
{
    if (init())
    {
        while (appletMainLoop() && m_running)
        {
            m_inputManager->update();

            update();
            draw();
            
            gfxFlushBuffers();
            gfxSwapBuffers();
            gfxWaitForVsync();
        }
    }
}

bool ConsoleScreen::init()
{
    if (!initSystems())
    {
        return false;
    }

    // Init screen componets
    m_inputManager = new ConsoleInputManager();
    m_inputManager->init();

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

        return false;
    }

    gfxInitDefault();
    consoleInit(NULL);

    return true;

    exit(0);
}

void ConsoleScreen::exitApp()
{
    m_running = false;

    onExit();

    m_currentScreen->onExit();
   
    m_screenList->destroy();
    delete m_screenList;

    m_inputManager->destroy();
    delete m_inputManager;
    
    gfxExit();
    romfsExit();

    exit(0);
}
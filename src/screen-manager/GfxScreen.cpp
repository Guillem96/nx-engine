#include "screen-manager/GfxScreen.h"

#include "exceptions/NxEngineException.h"

GfxScreen::GfxScreen()
{
}

GfxScreen::GfxScreen(int windowHeight, int windowWidth) : m_screenHeight(windowHeight),
                                                          m_screenWidth(windowWidth)
{
}

int GfxScreen::getScreenWidth() const
{
    return m_screenWidth;
}

int GfxScreen::getScreenHeight() const
{
    return m_screenHeight;
}

void GfxScreen::run()
{
    if (init())
    {
        while (m_running)
        {
            update();
            draw();
        }
    }
}

bool GfxScreen::init()
{
    if (!initSystems())
    {
        return false;
    }

    if (SDL_CreateWindowAndRenderer(m_screenWidth, m_screenHeight, 0, &m_window, NULL))
    {
        std::string errorMsg = "Couldn't create window: " + std::string(SDL_GetError());
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
        throw NxEngineException(errorMsg);
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

bool GfxScreen::initSystems()
{
    Result rc = romfsInit();
    if (rc)
    {
        throw NxEngineException("Error initializing RomFs");
        return false;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::string errorMsg = "Couldn't initialize SDL Video: " + std::string(SDL_GetError());
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        throw NxEngineException(errorMsg);
        return false;
    }

    return true;
}
void GfxScreen::exit()
{
    m_running = false;

    onExit();

    m_currentScreen->onExit();
    m_screenList->destroy();

    romfsExit();

    delete m_screenList;
    free(m_window);
}
#include "screen-manager/GfxScreen.h"

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
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
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
        // TODO: Throw exception
        return false;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // TODO: Throw exception
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
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
#include "screen-manager/GfxScreen.h"

#include "exceptions/NxEngineException.h"

GfxScreen::GfxScreen()
{
}

GfxScreen::GfxScreen(int windowHeight, int windowWidth) : m_screenHeight(windowHeight),
                                                          m_screenWidth(windowWidth)
{
}

GfxScreen::GfxScreen(const Color &color, int windowHeight, int windowWidth) : m_bgColor(color),
                                                                              m_screenHeight(windowHeight),
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
            m_inputManager->update();
            
            update();
            draw();

            SDL_RenderPresent(m_renderer);

            SDL_Color colour = m_bgColor.get();
            SDL_SetRenderDrawColor(m_renderer, colour.r, colour.g, colour.b, colour.a);
            SDL_RenderClear(m_renderer);
        }
    }
}

bool GfxScreen::init()
{
    if (!initSystems())
    {
        return false;
    }

    // Init the screen components
    m_inputManager = new GfxInputManager();

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
        return false;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::string errorMsg = "Couldn't initialize SDL Video: " + std::string(SDL_GetError());
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return false;
    }

    m_window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_FULLSCREEN);
    if (!m_window)
    {
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, 0, SDL_RENDERER_SOFTWARE);
    if (!m_renderer)
    {
        SDL_Quit();
        return false;
    }

    SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

    return true;
}
void GfxScreen::exitApp()
{
    m_running = false;

    onExit();

    m_currentScreen->onExit();

    m_screenList->destroy();
    delete m_screenList;

    m_inputManager->destroy();
    delete m_inputManager;

    romfsExit();
    
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_Quit();
}

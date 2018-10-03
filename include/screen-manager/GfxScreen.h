#pragma once

#include "screen-manager/IMainScreen.h"

#include <SDL2/SDL.h>
#include <switch.h>

#include "common/Color.h"
#include "common/Colors.h"
#include "common/GfxComponentFactory.h"

#include "input-manager/GfxInputManager.h"

class GfxScreen : public IMainScreen
{
  private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    Color m_bgColor = Colors::WHITESMOKE;

    int m_screenHeight = 720;
    int m_screenWidth = 1280;

    bool init();
    bool initSystems();

  public:
    GfxScreen();
    GfxScreen(int windowHeight, int windowWidth);
    GfxScreen(const Color &color, int windowHeight, int windowWidth);

    virtual ~GfxScreen() {}

    virtual int getScreenWidth() const override;
    virtual int getScreenHeight() const override;

    SDL_Window *getSDLWindow() { return m_window; }
    SDL_Renderer *getSDLRenderer() { return m_renderer; }

  protected:
    virtual void onInit() = 0;
    virtual void addScreens() = 0;
    virtual void onExit() = 0;

  public:
    virtual void run() override;
    virtual void exitApp() override;
};
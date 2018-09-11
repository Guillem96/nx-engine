#pragma once

#include "IMainScreen.h"

#define SCREEN_INDEX_NO_SCREEN -1

enum class ScreenState
{
    NONE,
    RUNNING,
    EXIT_APPLICATION,
    CHANGE_NEXT,
    CHANGE_PREVIOUS
};

class IScreen
{
  public:
    friend class ScreenList;

    IScreen()
    {
        // Empty
    }
    virtual ~IScreen()
    {
        // Empty
    }

    // Return the index of the next or previous screen when changing screens
    virtual int getNextScreenIndex() const = 0;
    virtual int getPreviousScreenIndex() const = 0;

    // Called at beginning and end of application
    virtual void build() = 0;
    virtual void destroy() = 0;

    // Called when a screen enters and exits focus
    virtual void onEntry() = 0;
    virtual void onExit() = 0;

    // Called in the main game loop
    virtual void update() = 0;
    virtual void draw() = 0;

    // Gets the index of the current screen
    int getScreenIndex() const
    {
        return m_screenIndex;
    }

    void setRunning()
    {
        m_currentState = ScreenState::RUNNING;
    }

    ScreenState getState() const { return m_currentState; }

    /// Sets m_screen to the parent game
    void setParentScreen(IMainScreen *screen) { m_screen = screen; }
    ScreenState m_currentState = ScreenState::NONE;

  protected:
    IMainScreen *m_screen = nullptr;
    int m_screenIndex = -1;
};
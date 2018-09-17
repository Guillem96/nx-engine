#pragma once
#include <vector>

class IMainScreen;
class IScreen;

class ScreenList
{
  public:
    ScreenList(IMainScreen *game);
    ~ScreenList();

    IScreen *moveNext();
    IScreen *movePrevious();

    void setScreen(int nextScreen);
    void addScreen(IScreen *newScreen);

    void destroy();

    IScreen *getCurrent();

  protected:
    IMainScreen *m_screen = nullptr;
    std::vector<IScreen *> m_screens;
    int m_currentScreenIndex = -1;
};
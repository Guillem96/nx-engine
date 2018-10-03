#pragma once

#include <nx-engine.h>

class DeveloperScreen : public IScreen
{
  private:
    int m_color = 0;
    InputManager *m_inputManager = nullptr;
    FontManager *m_fontManager = nullptr;

    Font *m_font = nullptr;
    Font *m_msgFont = nullptr;

    Text *m_message = nullptr;

    const int NUM_COLORS = 5;
    const Color COLORS[5] = {Colors::BLACK, Colors::BLUE, Colors::GREEN, Colors::RED, Colors::DARK};

  public:
    DeveloperScreen();
    ~DeveloperScreen();

    virtual int getNextScreenIndex() const override;
    virtual int getPreviousScreenIndex() const override;

    virtual void build() override;
    virtual void destroy() override;

    virtual void onEntry() override;
    virtual void onExit() override;

    virtual void update() override;
    virtual void draw() override;
};
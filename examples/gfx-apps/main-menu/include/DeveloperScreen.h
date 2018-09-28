#pragma once

#include <nx-engine.h>

class DeveloperScreen : public IScreen
{
  private:
    int m_color = 0;
    InputManager* m_inputManager = nullptr;

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
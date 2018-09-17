
#pragma once

#include <nx-engine.h>

class DisplayMessageScreen : public IScreen
{
  private:
    std::string m_message;

  public:
    DisplayMessageScreen(std::string message);
    ~DisplayMessageScreen();

    virtual int getNextScreenIndex() const override;
    virtual int getPreviousScreenIndex() const override;

    virtual void build() override;
    virtual void destroy() override;

    virtual void onEntry() override;
    virtual void onExit() override;

    virtual void update() override;
    virtual void draw() override;
};
#pragma once

#include <nx-engine.h>

#include <map>

class MenuScreen : public IScreen
{
private:
    int m_selectedOption = 0;
    std::map<std::string, int> m_menuEntries;
    
    void printMenu();
  public:
    MenuScreen();
    ~MenuScreen();

    virtual int getNextScreenIndex() const override;
    virtual int getPreviousScreenIndex() const override;

    virtual void build() override;
    virtual void destroy() override;

    virtual void onEntry() override;
    virtual void onExit() override;

    virtual void update() override;
    virtual void draw() override;
};
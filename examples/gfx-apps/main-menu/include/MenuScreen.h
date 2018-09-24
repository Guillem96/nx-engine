#pragma once

#include <nx-engine.h>

#include <map>
#include <vector>

class MenuScreen : public IScreen
{
private:
    int m_selectedOption = 0;
    std::map<std::string, int> m_menuEntries;

    std::vector<Text*> m_textEntries;
    Font* m_font = nullptr;
    Font* m_titleFont = nullptr;

    int getEntryIndex() const;

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
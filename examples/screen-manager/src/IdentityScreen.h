#pragma once

#include <nx-engine.h>

// Useless screen, it is only here because it must be at least one screen
class IdentityScreen : public IScreen
{

public:
    IdentityScreen() { }
    ~IdentityScreen() { }

    // Return the index of the next or previous screen when changing screens
    virtual int getNextScreenIndex() const override { return SCREEN_INDEX_NO_SCREEN; }
    virtual int getPreviousScreenIndex() const override { return SCREEN_INDEX_NO_SCREEN; }

    virtual void build() override {}
    virtual void destroy() override {}

    virtual void onEntry() override {}
    virtual void onExit() override {}

    virtual void update() override {}
    virtual void draw() override {}

};
#pragma once

#include <nx-engine.h>

#include <map>
#include <vector>

class SpritesScreen : public IScreen
{
  private:
    InputManager *m_inputManager = nullptr;
    SpriteRenderer *m_spriteRenderer = nullptr;

  public:
    SpritesScreen() {}
    ~SpritesScreen() {}

    virtual int getNextScreenIndex() const override { return SCREEN_INDEX_NO_SCREEN; }
    virtual int getPreviousScreenIndex() const override { return SCREEN_INDEX_NO_SCREEN; }

    virtual void build() override;
    virtual void destroy() override;

    virtual void onEntry() override {}
    virtual void onExit() override {}

    virtual void update() override;
    virtual void draw() override;
};
#pragma once

#include <nx-engine.h>

#include <map>
#include <vector>

class PolygonsScreen : public IScreen
{
  private:
    InputManager *m_inputManager = nullptr;
    // GeometricDrawer *m_geometricDrawer = nullptr;

    // std::vector<Figure *> m_figures;

  public:
    PolygonsScreen() {}
    ~PolygonsScreen() {}

    virtual int getNextScreenIndex() const override { return SCREEN_INDEX_NO_SCREEN; }
    virtual int getPreviousScreenIndex() const override { return SCREEN_INDEX_NO_SCREEN; }

    virtual void build() override;
    virtual void destroy() override;

    virtual void onEntry() override {}
    virtual void onExit() override {}

    virtual void update() override;
    virtual void draw() override;
};
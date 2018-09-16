#pragma once

#include <unordered_map>

#include "vectors/Vector2.h"

class EventManager
{
  private:
    bool wasKeyDown(unsigned int keyID);
    Vector2 *m_touchCords = nullptr;

  protected:
    std::unordered_map<unsigned int, bool> m_mapKey;
    std::unordered_map<unsigned int, bool> m_previousMapKey;

  public:
    EventManager() {}
    virtual ~EventManager() {}

    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);
    void setTouchCords(Vector2 cords);

    bool isKeyPressed(unsigned int keyID);
    bool isKeyUp(unsigned int keyID);
    bool isKeyDown(unsigned int keyID);

    // Returns null in case screen has not been touched during the current frame
    Vector2 *getTouchCords();
    virtual void init() = 0;
    virtual void update();
    virtual void destroy() = 0;
};
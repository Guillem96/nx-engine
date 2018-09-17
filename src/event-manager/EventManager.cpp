#include "event-manager/EventManager.h"

void EventManager::pressKey(unsigned int keyID)
{
    m_mapKey[keyID] = true;
}

void EventManager::releaseKey(unsigned int keyID)
{
    m_mapKey[keyID] = false;
}

bool EventManager::isKeyPressed(unsigned int keyID)
{
    return !wasKeyDown(keyID) && isKeyDown(keyID);
}

bool EventManager::isKeyUp(unsigned int keyID)
{
    return wasKeyDown(keyID) && !isKeyDown(keyID);
}

bool EventManager::isKeyDown(unsigned int keyID)
{
    auto it = m_mapKey.find(keyID);
    if (it != m_mapKey.end())
        return (*it).second;
    else
        return false;
}

bool EventManager::wasKeyDown(unsigned int keyID)
{
    auto it = m_previousMapKey.find(keyID);
    if (it != m_previousMapKey.end())
        return (*it).second;
    else
        return false;
}

void EventManager::update()
{
    for (auto &it : m_mapKey)
        m_previousMapKey[it.first] = it.second;
}

Vector2 *EventManager::getTouchCords()
{
    return m_touchCords;
}

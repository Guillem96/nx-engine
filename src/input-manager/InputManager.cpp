#include "input-manager/InputManager.h"

void InputManager::pressKey(unsigned int keyID)
{
    m_mapKey[keyID] = true;
}

void InputManager::releaseKey(unsigned int keyID)
{
    m_mapKey[keyID] = false;
}

bool InputManager::isKeyPressed(unsigned int keyID)
{
    return !wasKeyDown(keyID) && isKeyDown(keyID);
}

bool InputManager::isKeyUp(unsigned int keyID)
{
    return wasKeyDown(keyID) && !isKeyDown(keyID);
}

bool InputManager::isKeyDown(unsigned int keyID)
{
    auto it = m_mapKey.find(keyID);
    if (it != m_mapKey.end())
        return (*it).second;
    else
        return false;
}

bool InputManager::wasKeyDown(unsigned int keyID)
{
    auto it = m_previousMapKey.find(keyID);
    if (it != m_previousMapKey.end())
        return (*it).second;
    else
        return false;
}

void InputManager::update()
{
    for (auto &it : m_mapKey)
        m_previousMapKey[it.first] = it.second;
}

Vector2 *InputManager::getTouchCords()
{
    return m_touchCords;
}

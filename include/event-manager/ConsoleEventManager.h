#pragma once

#include <switch.h>

#include <map>

#include "EventManager.h"

class ConsoleEventManager : public EventManager
{   
    static const int PAD_BUTTONS = 24;
    static constexpr HidControllerKeys PAD[PAD_BUTTONS] = {
        KEY_A, KEY_B, KEY_X, KEY_Y,
        KEY_LSTICK, KEY_RSTICK,
        KEY_L, KEY_R,
        KEY_ZL, KEY_ZR,
        KEY_PLUS, KEY_MINUS,
        KEY_DLEFT, KEY_DUP, KEY_DRIGHT, KEY_DDOWN,
        KEY_LSTICK_LEFT, KEY_LSTICK_UP, KEY_LSTICK_RIGHT, KEY_LSTICK_DOWN,
        KEY_RSTICK_LEFT, KEY_RSTICK_UP, KEY_RSTICK_RIGHT, KEY_RSTICK_DOWN
    };

  public:
    ConsoleEventManager() {}
    ~ConsoleEventManager() {}

    virtual void init() override;
    virtual void update() override;
    virtual void destroy() override;
};
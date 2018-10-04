#pragma once

enum ScreenAlignFlags
{
    FREE = 0x0,
    // Horizontal alignment
    LEFT = 0x1,
    CENTER = 0x2,
    RIGHT = 0x4,
    // Vertical
    TOP = 0x8,
    MIDDLE = 0x10,
    BOTTOM = 0x20,
};
#pragma once
class Vector2
{
  public:
    Vector2() : x(.0f), y(.0f) {}
    Vector2(float value) : x(value), y(value) {}
    Vector2(float xValue, float yValue) : x(xValue), y(yValue) {}

    ~Vector2() {}

    float x;
    float y;
};
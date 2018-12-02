#pragma once

class Vector3
{
  public:
    Vector3() : x(.0f), y(.0f), z(.0f) {}
    Vector3(float value) : x(value), y(value), z(value) {}
    Vector3(float xValue, float yValue, float zValue) : x(xValue), y(yValue), z(zValue) {}

    ~Vector3() {}

    float x;
    float y;
    float z;
};
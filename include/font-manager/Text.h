#pragma once

#include <string>

#include "font-manager/Font.h"
#include "vectors/Vector2.h"

class Text
{
private:
    std::string m_text;
    Font* m_font = nullptr;
    Vector2 m_position;
public:
    Text(const std::string& text, Font* font, const Vector2& position);
    ~Text();

    const std::string& getText() const;
    const Vector2& getPosition() const;

    void setText(const std::string& text);
    void setPosition(const Vector2& position);
};
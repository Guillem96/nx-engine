#pragma once

#include <string>

#include "font-manager/Font.h"
#include "vectors/Vector2.h"
#include "common/Color.h"

class Text
{
private:
    std::string m_text;
    Font* m_font = nullptr;
    Vector2 m_position;
    Color m_color;
public:
    Text(const std::string& text, Font* font, const Vector2& position, const Color& color);
    ~Text();

    const std::string& getText() const;
    const Vector2& getPosition() const;
    const Font* getFont() const;
    const Color& getColor() const;
    const Vector2 getTextDims();

    void setText(const std::string& text);
    void setPosition(const Vector2& position);
    void setColor(const Color& color);
};
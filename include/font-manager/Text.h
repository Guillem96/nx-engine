#pragma once

#include <string>

#include "font-manager/Font.h"
#include "common/IDrawable.h"
#include "common/Color.h"

class Text : public IDrawable
{
  private:
    std::string m_text;
    Font *m_font = nullptr;
    Color m_color;

  public:
    Text(const std::string &text, Font *font, const Vector2 &position, const Color &color);
    Text(const std::string &text, Font *font, const Vector2 &position, const Color &color, unsigned int align);

    ~Text();

    const std::string &getText() const;
    const Font *getFont() const;
    const Color &getColor() const;
    const Vector2 getTextDims();

    void setText(const std::string &text);
    void setColor(const Color &color);
};
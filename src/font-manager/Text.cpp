#include "font-manager/Text.h"

Text::Text(const std::string &text, Font *font, const Vector2 &position, const Color &color)
    : IDrawable(position),
      m_text(text),
      m_font(font),
      m_color(color)
{
}

Text::Text(const std::string &text, Font *font, const Vector2 &position, const Color &color, unsigned int align)
    : IDrawable(position, align),
      m_text(text),
      m_font(font),
      m_color(color)
{
}

Text::~Text()
{
}

const std::string &Text::getText() const
{
    return m_text;
}

const Font *Text::getFont() const
{
    return m_font;
}

const Color &Text::getColor() const
{
    return m_color;
}

const Vector2 Text::getTextDims()
{
    int w, h;
    TTF_SizeText(m_font->get(), m_text.c_str(), &w, &h);
    return Vector2((float)w, (float)h);
}

void Text::setText(const std::string &text)
{
    m_text = text;
}

void Text::setColor(const Color &color)
{
    m_color = color;
}

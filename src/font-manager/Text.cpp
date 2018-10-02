#include "font-manager/Text.h"

Text::Text(const std::string &text, Font *font, const Vector2 &position, const Color &color)
    : m_text(text),
      m_font(font),
      m_position(position),
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

const Vector2 &Text::getPosition() const
{
    return m_position;
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

float Text::getPaddingLeft() const
{
    return m_paddingLeft;
}

float Text::getPaddingRight() const
{
    return m_paddingRight;
}

float Text::getPaddingTop() const
{
    return m_paddingTop;
}

float Text::getPaddingBottom() const
{
    return m_paddingBottom;
}

void Text::setText(const std::string &text)
{
    m_text = text;
}

void Text::setPosition(const Vector2 &position)
{
    m_position = position;
}

void Text::setColor(const Color &color)
{
    m_color = color;
}

void Text::setPaddings(float left, float top, float right, float bottom)
{
    setPaddingLeft(left);
    setPaddingTop(top);
    setPaddingRight(right);
    setPaddingBottom(bottom);
}

void Text::setPaddingLeft(float p)
{
    m_paddingLeft = p;
}

void Text::setPaddingRight(float p)
{
    m_paddingRight = p;
}

void Text::setPaddingTop(float p)
{
    m_paddingTop = p;
}

void Text::setPaddingBottom(float p)
{
    m_paddingBottom = p;
}
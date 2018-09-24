#include "font-manager/Text.h"

Text::Text(const std::string &text, Font *font, const Vector2 &position) : m_text(text), m_font(font), m_position(position)
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

void Text::setText(const std::string &text) 
{
    m_text = text;
}

void Text::setPosition(const Vector2 &position) 
{
    m_position = position;
}
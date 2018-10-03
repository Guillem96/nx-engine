#include "MenuScreen.h"
#include "ScreenIndex.h"

MenuScreen::MenuScreen()
{
    m_menuEntries["Developer Info"] = DEVELOPER_SCREEN_INDEX;
    m_menuEntries["License Info"] = LICENSE_SCREEN_INDEX;
}

MenuScreen::~MenuScreen()
{
}

int MenuScreen::getNextScreenIndex() const
{
    int nextIndex = getEntryIndex();
    return nextIndex;
}

int MenuScreen::getPreviousScreenIndex() const
{
    return SCREEN_INDEX_NO_SCREEN;
}

void MenuScreen::build()
{
    // Create the InputManager component using a factory
    m_inputManager = m_screen->factory()->createInputManager();
    m_inputManager->init();

    // Create the InputManager component using a factory
    m_fontManager = m_screen->factory()->createFontManager((GfxScreen *)m_screen);
    m_fontManager->init();

    // Build title
    m_titleFont = new Font("romfs:/Pacifico.ttf", 100);

    // Can OR alignments but one must be from horizontal alignment and the other from vertical alignment
    Text *title = new Text("MAIN MENU", m_titleFont, Vector2(), Colors::BLACK, TextAlignFlags::TOP | TextAlignFlags::CENTER);
    m_fontManager->addText(title);

    // Build menu entries and controls
    int fontSize = 30;
    m_font = new Font("romfs:/Raleway-Regular.ttf", fontSize);
    for (auto &it : m_menuEntries)
    {
        Text *t = new Text(it.first, m_font, Vector2(0.0f, 200.0f + (fontSize + 10.0f) * (float)m_textEntries.size()), Colors::BLACK, TextAlignFlags::LEFT);
        t->setPaddingLeft(100.0f);
        m_textEntries.push_back(t);
        m_fontManager->addText(t);
    }

    // Build controls
    Text *controls = new Text("Press B to exit, A to select an entry or arrows to navigate", m_font, Vector2(), Colors::RED, TextAlignFlags::BOTTOM | TextAlignFlags::CENTER);
    m_fontManager->addText(controls);
}

void MenuScreen::destroy()
{
    m_textEntries.clear();
    m_menuEntries.clear();
    delete m_font;

    m_inputManager->destroy();
    delete m_inputManager;

    m_fontManager->destroy();
    delete m_fontManager;
}

void MenuScreen::onEntry()
{
}

void MenuScreen::onExit()
{
    m_inputManager->clear(); // Clear events to avoid strange scenarions (recommended)
}

void MenuScreen::update()
{
    m_inputManager->update();

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_A))
    {
        m_currentState = ScreenState::CHANGE_NEXT;
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::EXIT_APPLICATION;
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_DDOWN) || m_inputManager->isKeyPressed(JoyconButtons::J_KEY_LSTICK_DOWN))
    {
        if (m_selectedOption != (int)m_menuEntries.size() - 1)
            m_selectedOption++;
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_DUP) || m_inputManager->isKeyPressed(JoyconButtons::J_KEY_LSTICK_UP))
    {
        if (m_selectedOption != 0)
            m_selectedOption--;
    }

    for (Text *t : m_textEntries)
    {
        t->setColor(Colors::BLACK);
    }
    m_textEntries[m_selectedOption]->setColor(Colors::BLUE);
}

void MenuScreen::draw()
{
    m_fontManager->draw();
}

int MenuScreen::getEntryIndex() const
{
    int idx = 0;
    for (auto &it : m_menuEntries)
    {
        if (idx == m_selectedOption)
            return it.second;

        idx++;
    }
    return SCREEN_INDEX_NO_SCREEN;
}
#include "PolygonsScreen.h"

void PolygonsScreen::build()
{
    // Create the InputManager component using a factory
    m_inputManager = m_screen->factory()->createInputManager();
    m_inputManager->init();

    // Create the Geometric drawer component using a factory
    m_geometricDrawer = m_screen->factory()->createGeometricDrawer((GfxScreen *)m_screen);
    m_geometricDrawer->init();

    // Create the InputManager component using a factory
    m_fontManager = m_screen->factory()->createFontManager((GfxScreen *)m_screen);
    m_fontManager->init();

    m_titleFont = new Font("romfs:/fonts/Raleway-Regular.ttf", 100);

    // Can OR alignments but one must be from horizontal alignment and the other from vertical alignment
    Text *title = new Text("Geometric Drawer", m_titleFont, Vector2(), Colors::BLACK, ScreenAlignFlags::TOP | ScreenAlignFlags::CENTER);
    m_fontManager->addText(title);

    // Creating some figures using figure builder (It is recomended over figures specific constructors)
    Figure *ellipse = FigureBuilder()
                          .strokeColor(Colors::GREEN)
                          ->backgroundColor(Colors::DARK)
                          ->center(Vector2(200.0f, 200.0f))
                          ->radius(Vector2(30.0f, 60.0f))
                          ->filled()
                          ->bordered()
                          ->build();

    Figure *rectangle = FigureBuilder()
                            .backgroundColor(Colors::RED)
                            ->position(Vector2(400.0f, 400.0f))
                            ->size(Vector2(200.0f, 300.0f))
                            ->filled()
                            ->build();

    Figure *line = FigureBuilder()
                       .color(Colors::BLUE)
                       ->width(20.0f)
                       ->point(new Vector2(10.0f, 80.0f))
                       ->point(new Vector2(1000.0f, 80.0f))
                       ->build();

    m_geometricDrawer->add(ellipse);
    m_geometricDrawer->add(rectangle);
    m_geometricDrawer->add(line);
}

void PolygonsScreen::destroy()
{
    m_inputManager->destroy();
    delete m_inputManager;

    m_geometricDrawer->destroy();
    delete m_geometricDrawer;

    m_fontManager->destroy();
    delete m_fontManager;

    delete m_titleFont;
}

void PolygonsScreen::update()
{
    m_inputManager->update();

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_B))
    {
        m_currentState = ScreenState::EXIT_APPLICATION;
    }
}

void PolygonsScreen::draw()
{
    m_geometricDrawer->draw();
    m_fontManager->draw();
}
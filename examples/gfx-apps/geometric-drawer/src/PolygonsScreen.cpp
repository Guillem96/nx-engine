#include "PolygonsScreen.h"

void PolygonsScreen::build()
{
    // Create the InputManager component using a factory
    m_inputManager = m_screen->factory()->createInputManager();
    m_inputManager->init();

    // Create the Geometric drawer component using a factory
    // m_geometricDrawer = m_screen->factory()->createGeometricDrawer((GfxScreen *)m_screen);
    // m_geometricDrawer->init();

    // Creating some figures using figure builder (It is recomended over figures specific constructors)
    // Figure *ellipse = FigureBuilder()
    //                       .strokeColor(Colors::GREEN)
    //                       ->backgroundColor(Colors::DARK)
    //                       ->center(new Vector2(200.0f, 200.0f))
    //                       ->radius(new Vector2(30.0f, 60.0f))
    //                       ->filled()
    //                       ->build();

    // Figure *rectangle = FigureBuilder()
    //                         .strokeColor(Colors::DARK)
    //                         ->backgroundColor(Colors::RED)
    //                         ->position(new Vector2(400.0f, 400.0f))
    //                         ->size(new Vector2(50.0f, 50.0f))
    //                         ->filled()
    //                         ->build();

    // Figure *line = FigureBuilder()
    //                    .color(Colors::BLUE)
    //                    ->point(new Vector2(10.0f, 10.0f))
    //                    ->point(new Vector2(1000.0f, 10.0f))
    //                    ->build();

    // m_geometricDrawer->add(ellipse);
    // m_geometricDrawer->add(rectangle);
    // m_geometricDrawer->add(line);
}

void PolygonsScreen::destroy()
{
    m_inputManager->destroy();
    delete m_inputManager;

    // m_geometricDrawer->destroy();
    // delete m_geometricDrawer;
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
    // m_geometricDrawer->draw();
}
# Geometric Drawer

## Geometric Drawer geometric shapes

- [Rectangle](../include/geometric-drawer/Rectangle.h)
- [Triangle](../include/geometric-drawer/Triangle.h)
- [Ellipse](../include/geometric-drawer/Ellipse.h)
- [Line](../include/geometric-drawer/Line.h)
- [Free Figure (Build your own figures adding custom vertices)](../include/geometric-drawer/Figure.h)

## Geometric Drawer API

Take a look to [GeometricDrawer.h](../include/geometric-drawer/GeometricDrawer.h)

## How to use Geometric Drawer

In the build method of an IScreen you are able to create the GeometricDrawer object using the following instruction: ``m_screen->factory()->createGeometricDrawer((GfxScreen *)m_screen)``, where ``m_screen`` is the reference to our GfxScreenManager.
Be careful because GeometricDrawer needs a reference to a GfxScreen, so it means that you won't be able to create a GeometricDrawer object when you are working with a ConsoleScreen.

*Example:*

See examples directory

```cpp
// Create it using the ComponentFactory at build method
void MyScreen::build()
{
  // Create the Geometric drawer component using a factory
  m_geometricDrawer = m_screen->factory()->createGeometricDrawer((GfxScreen *)m_screen);
  m_geometricDrawer->init();

  // Creating some figures using figure builder (It is recomended over figures specific constructors)
  Figure *ellipse = FigureBuilder()
                        .strokeColor(Colors::GREEN)
                        ->backgroundColor(Colors::DARK)
                        ->center(Vector2(200.0f, 200.0f)) // This will be an ellipse because we are using center and radius methods
                        ->radius(Vector2(30.0f, 60.0f))
                        ->filled()
                        ->bordered()
                        ->build();

  Figure *rectangle = FigureBuilder()
                          .backgroundColor(Colors::RED)
                          ->position(Vector2(400.0f, 400.0f)) // This will we a rectangle because we are using position and size methods
                          ->size(Vector2(200.0f, 300.0f))
                          ->filled()
                          ->build();

  Figure *line = FigureBuilder()
                      .color(Colors::BLUE)
                      ->width(20.0f)
                      ->point(new Vector2(10.0f, 80.0f)) // This will be a line because it has 2 points
                      ->point(new Vector2(1000.0f, 80.0f))
                      ->build();

  m_geometricDrawer->add(ellipse);
  m_geometricDrawer->add(rectangle);
  m_geometricDrawer->add(line);
}


void MyScreen::draw()
{
    m_geometricDrawer->draw(); // Do not forget to call draw or you will get the screen empty
}

void MyScreen::destroy()
{
  m_geometricDrawer->destroy();
  delete m_geometricDrawer;
}
```
# Input Manager

- Allows to read any kind of input of the Console
- InputManager wraps libnx(In case of ConsoleScreen) code or SDL2(In case of GfxScreen) code to catch the inputs of the console, So you will be able to use an Input system without having any knowledge of SDL2 or libnx.

```cpp
// Returns true if the key has been pressed on the current frame
bool isKeyPressed(unsigned int keyID);
// Returns true if the key is released on the current frame
bool isKeyUp(unsigned int keyID);
// Returns true if the key is hold down
bool isKeyDown(unsigned int keyID);

// Returns null in case screen has not been touched during the current frame
// Retrurns the releative coordinates of the touch
Vector2 *getTouchCords();
```

## Key Codes
- J_KEY_A
- J_KEY_B
- J_KEY_X
- J_KEY_Y
- J_KEY_LSTICK
- J_KEY_RSTICK
- J_KEY_L
- J_KEY_R
- J_KEY_ZL
- J_KEY_ZR
- J_KEY_PLUS
- J_KEY_MINUS
- J_KEY_DLEFT
- J_KEY_DUP
- J_KEY_DRIGHT
- J_KEY_DDOWN
- J_KEY_LSTICK_LEFT
- J_KEY_LSTICK_UP
- J_KEY_LSTICK_RIGHT
- J_KEY_LSTICK_DOWN
- J_KEY_RSTICK_LEFT
- J_KEY_RSTICK_UP
- J_KEY_RSTICK_RIGHT
- J_KEY_RSTICK_DOWN

## How to use InputManager

In the update method of an IScreen you are able to create the InputManager using the following instruction: ``m_screen->factory()->createInputManager()``, where ``m_screen`` is the reference to our ScreenManager (Console or Gfx ScreenManager).

*Example:*

```cpp
// Create it using the ComponentFactory at build method
void MyScreen::build()
{
  m_inputManager = m_screen->factory()->createInputManager();
  m_inputManager->init();
}

void MyScreen::update()
{
    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_DRIGHT))
    {
      // Your code here
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_DLEFT))
    {
      // Your code here
    }

    if (m_inputManager->isKeyPressed(JoyconButtons::J_KEY_PLUS))
    {
      // Your code here
    }
}

void MyScreen::destroy()
{
  m_inputManager->destroy();
  delete m_inputManager;
}
```
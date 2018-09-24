# NxEngine

An abstraction layer to develop easily apps for Nintendo Switch.

NxEngine uses libnx, devkitARM and switch-SDL2. 

## Docs

### Screen Manager

- There are two types of ScreenManager, ScreenManager can be seen as the application controller.
  - ``ConsoleScreen``: Allows you to work on a console environment.
  - ``GfxScreen``: Allows yo to render graphic elements.
- Both ScreenManagers have the responsible to store all the differents screens of the application.
- ScreenManager allows you to navigate between diferents screens (IScreen). 
- Each IScreen will have the ``update()`` and ``draw()`` methods, boths methods will be called each frame.
  - Use ``update()`` to update any kind of data (database, variables...), catch input events...
- Related examples:
  - [Console MainMenu](examples/console-apps/main-menu)
  - [Navigate between screens](examples/console-app/navigate-between-screens)
*Header file of a ConsoleScreen Manager*

```cpp
// Inhertir from ConsoleScreen
class ConsoleApp : public ConsoleScreen
{
  public:
    ConsoleApp();
    ~ConsoleApp();

    virtual void onInit() override;
    virtual void addScreens() override;
    virtual void onExit() override;
};
```
#### IScreen

- IScreen represents a screen of the application
- IScreens are referenciated using Integer index, depending on the  order that they are added on the ScreenManager.

*Screen index examples*

Take a look to this [example](examples/console-apps/main-menu/src/ConsoleApp.cpp) and this [header file](examples/console-apps/main-menu/include/ScreenIndex.h).

To see more look at [IScreen.h](include/screen-manager/IScreen.h)

*Header file of an IScreen*
```cpp
class MyScreen : public IScreen
{
  public:
    MyScreen();
    ~MyScreen();

    // Called when the status of screen is changed to CHANGE_NEXT
    // Returns the desired screen index to navigate
    virtual int getNextScreenIndex() const override;
    // Called when the status of screen is changed to CHANGE_PREVIOUS
    // Returns the desired screen index to navigate
    virtual int getPreviousScreenIndex() const override;

    // Called on app start and app exit
    virtual void build() override;
    virtual void destroy() override;

    // Called when this screen becomes the displayed screen
    virtual void onEntry() override;
    virtual void onExit() override;

    // Called each frame
    virtual void update() override;
    virtual void draw() override;
};
```
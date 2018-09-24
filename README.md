# NxEngine

An abstraction layer to develop easily apps for Nintendo Switch.

NxEngine uses libnx, devkitARM and switch-SDL2. 

## Docs

- [ScreenManager](docs/ScreenManager.md)
- [InputManager](docs/InputManager.md)

## Install dependencies

- [Install pacman](https://devkitpro.org/wiki/Getting_Started)
- Install switch development and portlibs.

```
$ pacman -S $(pacman -Ssq switch-*)
```
## Use it for your app

### Architecture

```javascript
your-app
|-- include/                // Your header files goes here
|-- libs/                   // Your libs
|     |-- nxengine          // Inside your libs put nxengine
|           |-- include/  
|           |-- lib/
|-- romfs/                  // Mandatory if using NxEngine
|-- src/                    // Your source files
|-- output/                 // Directory wher nro, nso... will be generated
|-- Makefile                // NxEngine Makefile
```

## License

This project is licensed under the GPL License - see the [LICENSE](LICENSE) file for details.
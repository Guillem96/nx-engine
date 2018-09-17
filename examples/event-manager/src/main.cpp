#include <nx-engine.h>
#include <switch.h>

int main(int argc, char const *argv[])
{
    gfxInitDefault();
    consoleInit(NULL);

    GfxEventManager e = GfxEventManager();
    e.init();

    printf("Hello world\n");

    while (appletMainLoop())
    {
        e.update();
        gfxFlushBuffers();
        gfxSwapBuffers();
    }

    gfxExit();
    return 0;
}

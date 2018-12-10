#include "GfxApp.h"

int main(int argc, char const *argv[])
{
    GfxApp ga = GfxApp(Color(134, 188, 252));
    ga.run();

    socketExit();
    return 0;
}

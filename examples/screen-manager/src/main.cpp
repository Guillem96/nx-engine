#include "ScreenController.h"

int main(int argc, char const *argv[])
{
    // Run the app
    ScreenController sc(Color(255, 127, 80), 720, 1280);
    sc.run();
    return 0;
}

#include "ConsoleApp.h"

int main(int argc, char const *argv[])
{
    std::vector<std::string> messages = {"I am on the first screen", "Oh! Now on the second one", "It is really working? It is awesome"};
    ConsoleApp ca = ConsoleApp(messages);
    ca.run();
    return 0;
}

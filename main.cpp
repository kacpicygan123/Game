#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "gra.h"

using namespace std;

int main()
{
    bool running=true;
    Game game;
    game.Init();
    while (running)
    {
        game.ShowMenu();
    }
}

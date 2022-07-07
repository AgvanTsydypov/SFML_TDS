#include "App.h"

int main()
{
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    App app;

    app.initApp();

    app.launchGame();

    app.mainLoop();


    //_CrtDumpMemoryLeaks();
    return 0;
}
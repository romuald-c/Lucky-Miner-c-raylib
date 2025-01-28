#include <stdio.h>
#include <raylib.h>

int main(void)
{
    /*printf("\n\n");           // Compiler test.
    printf("Hello Romuald!");
    printf("\n\n");
    */

    InitWindow(1280, 720, "Lucky Miner!");      //opening the window (size 1280x720) with name 'Hello Romuald'
    SetTargetFPS(60);                           //Refresh rate (60 Frames Per Second)

    //-------Start the Game main Loop---------------
    while(!WindowShouldClose())
    {
        BeginDrawing();
                                 //From this point we begin to draw.
        ClearBackground(DARKGRAY);              // Setting the background color to  dark gray 
        
        DrawText("Welcome to \"Lucky Miner\" Game!", 140, 30, 20, RED);   //Writting the text in the windows 'Hello Louie!' position in the window and the color
        
        
        EndDrawing();                           //After this point there is no more drawing.
    }
    CloseWindow();                              //Closing the window.

    return 0;
}

#include <stdio.h>
#include <raylib.h>

int screenX = 1280;
int screenY = 720;

int main(void)
{

    int circCentreX = screenX / 2;
    int circCentreY = screenY - 30;
    int speed = 5;
    int speed2 = 1;
    int circSize = 20;

    InitWindow(screenX, screenY, "Lucky Miners!");      //opening the window (size 1280x720) with name 'Hello Romuald'

    SetTargetFPS(60);    //Refresh rate (60 Frames Per Second)                              

    //-------Start the Game main Loop---------------
    while(!WindowShouldClose())
    {
        // moovement of the circle.
        if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP) && circCentreX <= screenX - 30 && circCentreY >= 30)
        {
            circCentreX += speed;
            circCentreY -= speed;
        }
        else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN) && circCentreX <= screenX - 30 && circCentreY <= screenY - 30)
        {
            circCentreX += speed;
            circCentreY += speed;
        }
        else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP) && circCentreX >= 30 && circCentreY >= 30)
        {
            circCentreX -= speed;
            circCentreY -= speed;
        }
        else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN) && circCentreX >= 30 && circCentreY <= screenY - 30)
        {
            circCentreX -= speed;
            circCentreY += speed;
        }

        else if(IsKeyDown(KEY_UP) && circCentreY >= 30)
        {
            circCentreY -= speed;
        }
        else if (IsKeyDown(KEY_DOWN) && circCentreY <= screenY - 30)
        {
            circCentreY += speed;
        }
        else if (IsKeyDown(KEY_LEFT) && circCentreX >= 30)
        {
            circCentreX -= speed;
        }
        else if (IsKeyDown(KEY_RIGHT) && circCentreX <= screenX - 30)
        {
            circCentreX += speed;
        }


        // Size of the circle.
        if(IsKeyDown(KEY_Z))
        {
            circSize -= speed2;
        }
        else if (IsKeyDown(KEY_X))
        {
            circSize += speed2;
        }

        BeginDrawing();         //From this point we begin to draw.
                                 
        ClearBackground(DARKGRAY);              // Setting the background color to  dark gray 
        
        DrawRectangle(700, 300, 500, 80, MAGENTA);

        DrawCircle(circCentreX, circCentreY, circSize, GREEN);

        DrawText("Welcome to \"Lucky Miner\" Game!", 30, 100, 50, RED);   //Writting the text in the windows 'Welcome.....' position in the window and the color
        
        
        EndDrawing();                           //After this point there is no more drawing.
    }
    CloseWindow();                              //Closing the window.

    return 0;
}

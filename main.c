#include <stdio.h>
#include <raylib.h>

int screenX = 1280;
int screenY = 720;
#define HERO_COUNT 9

int main(void)
{

    int circCentreX = screenX / 2;
    int circCentreY = screenY - 30;
    int speed = 5;
    int speedcross = 4;
    int speed2 = 1;
    int circSize = 20;
    int heroIndex = 0;

    InitWindow(screenX, screenY, "Lucky Miners!");      //opening the window (size 1280x720) with name 'Hello Romuald'

    Texture2D heroMoove = LoadTexture("assets/images/hero02.png");
    //Rectangle heroRec = {0 , 50, heroMoove.width / 9, heroMoove.height / 4};
    
    SetTargetFPS(60);    //Refresh rate (60 Frames Per Second)                              
    
    Vector2 HeroPos = {screenX / 2, screenY / 2};
    Vector2 HeroPosition2 = {(screenX / 2) - 100, screenY / 2};
    Vector2 HeroAngle = {40, 50};
    
    //-------Start the Game main Loop---------------
    while(!WindowShouldClose())
    {
        // moovement of the circle.
        if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP) && circCentreX <= screenX - 30 && circCentreY >= 30)
        {
            circCentreX += speedcross;
            circCentreY -= speedcross;
        }
        else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN) && circCentreX <= screenX - 30 && circCentreY <= screenY - 30)
        {
            circCentreX += speedcross;
            circCentreY += speedcross;
        }
        else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP) && circCentreX >= 30 && circCentreY >= 30)
        {
            circCentreX -= speedcross;
            circCentreY -= speedcross;
        }
        else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN) && circCentreX >= 30 && circCentreY <= screenY - 30)
        {
            circCentreX -= speedcross;
            circCentreY += speedcross;
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
        // movement of the hero
        if (IsKeyDown(KEY_O))
        {
            heroIndex++;
            if (heroIndex >= HERO_COUNT)
            {
                heroIndex = 0;
            }
            
        }
        if (IsKeyDown(KEY_P))
        {
            heroIndex--;
            if (heroIndex < 0)
            {
                heroIndex = HERO_COUNT - 1;
            }
            
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
        
        //DrawTexturePro(heroMoove, { 0.0f, 0.0f, (float)heroMoove.width, (float).height}, {10, 10, 100, 100}, {0, 0}, 0.0f, WHITE);
        DrawRectangle(700, 300, 500, 80, MAGENTA);
        
        Rectangle heroRec = {heroIndex * 50, 50, 50, 50}; 
        Rectangle heroPosRec = {100 , 150, 80, 100};            // ------- zanimowac to prosze----------
        //DrawTexture(heroMoove, HeroPos.x, HeroPos.y, WHITE);
        //DrawTexture(heroMoove, 0, 0, WHITE);
        DrawTextureRec(heroMoove, heroRec, HeroPos, WHITE);
        //DrawTextureEx(heroMoove, HeroPosition2, 0.5f, 1.2f, WHITE);
        DrawTexturePro(heroMoove, heroRec, heroPosRec, HeroAngle, 0.0f, WHITE);
        
        DrawCircle(circCentreX, circCentreY, circSize, GREEN);
        
        DrawText("Welcome to \"Lucky Miner\" Game!", 30, 100, 50, RED);   //Writting the text in the windows 'Welcome.....' position in the window and the color
        
        
        EndDrawing();                           //After this point there is no more drawing.
    }
    UnloadTexture(heroMoove);
    CloseWindow();                              //Closing the window.
    
    return 0;
}

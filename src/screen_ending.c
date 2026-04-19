#include "tafa.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Ending Screen Functions Definition
//----------------------------------------------------------------------------------

// Ending Screen Initialization logic
void InitEndingScreen(t_ending *ending)
{
    // TODO: Initialize ENDING screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    ending->died_image = LoadTextureFromFile("resources/died.png");
}

// Ending Screen Update logic
void UpdateEndingScreen(void)
{
    // TODO: Update ENDING screen variables here!

    // Press enter or tap to return to TITLE screen
    if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 1;
        if (IsAudioDeviceReady() && fxCoinLoaded)
            PlaySound(fxCoin);
    }
}

// Ending Screen Draw logic
void DrawEndingScreen(t_ending ending)
{
    // TODO: Draw ENDING screen here!
    DrawRectangle(0, 0, screen_width, screen_height, BLACK);

    const char *gmText = "RESY IANAO";
    const int gmWidth = MeasureText(gmText, 50);
    Vector2 diePos = (Vector2){screen_width / 2 - ending.died_image.width / 2, screen_height / 2 - ending.died_image.height};
    DrawRectangle(0, diePos.y + 300, screen_width, ending.died_image.height / 4, GRAY);
    DrawTextureEx(ending.died_image, diePos, 0.0f, 1.0f, WHITE);
    DrawText(gmText, screen_width / 2 - gmWidth / 2, screen_height / 2, 50, WHITE);
}

// Ending Screen Unload logic
void UnloadEndingScreen(t_ending *ending)
{
    // TODO: Unload ENDING screen variables here!
    UnloadTexture(ending->died_image);
}

// Ending Screen should finish?
int FinishEndingScreen(void)
{
    return finishScreen;
}

#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
static Rectangle option_rec = {0};

//----------------------------------------------------------------------------------
// Options Screen Functions Definition
//----------------------------------------------------------------------------------

// Options Screen Initialization logic
void InitOptionsScreen(void)
{
    // TODO: Initialize OPTIONS screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    option_rec = (Rectangle){SCREEN_WIDTH * 0.10,
        SCREEN_HEIGHT * 0.10,
        (SCREEN_WIDTH * 0.90) - (SCREEN_WIDTH * 0.10),
        (SCREEN_HEIGHT * 0.90) - (SCREEN_HEIGHT * 0.10)};
}

// Options Screen Update logic
void UpdateOptionsScreen(void)
{
    // TODO: Update OPTIONS screen variables here!
}

// Options Screen Draw logic
void DrawOptionsScreen(void)
{
    DrawRectangleRec((Rectangle){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, GRAY);
    DrawRectangleLinesEx(option_rec, 8, DARKGRAY);
    // TODO: Draw OPTIONS screen here!
}

// Options Screen Unload logic
void UnloadOptionsScreen(void)
{
    // TODO: Unload OPTIONS screen variables here!
}

// Options Screen should finish?
int FinishOptionsScreen(void)
{
    return finishScreen;
}
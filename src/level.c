#include "level.h"

float timer = 0.0f;

void LoadLevel(t_level *level, SubGameScreen levelType)
{
    level->type = levelType;
    level->name = "Level 1";

    if (level->type == LEVEL_1)
    {
        level->one.prologue_text[1] = "Ao anaty tontolo feno aizina,";                            //"Dans un monde plongé dans les ténèbres,",
        level->one.prologue_text[2] = "izay hanjakan'ny tahotra sy fahadisoam-panantenana,";      //"où la peur et le désespoir règnent en maîtres,",
        level->one.prologue_text[3] = "izay ny tsirairay dia gejain'ny safidiny sy ny filàny..."; //"où chacun est prisonnier de ses choix et désirs...",
        level->one.prologue_text[4] = "raha tsy...";
        level->one.black_box = (Rectangle){screen_width * 0.8, screen_height * 0.85, screen_width * 0.05, screen_width * 0.05};
        level->one.show_quiz = false;
        level->one.hide_text = false;
    }
}

void UpdateLevel(t_level *level, float dt, t_player *player)
{
    UpdatePlayer(player, dt);
    if (level->type == LEVEL_1)
    {
        if (timer <= 5.0f)
        {
            timer += dt * 1.0f;
            level->one.hide_text = false;
            player->can_move = false;
        }
        else
        {
            level->one.hide_text = true;
            player->can_move = true;
        }
        Rectangle hitbox = {
            player->pos.x - player->pos.width / 4,
            player->pos.y - player->pos.height / 4,
            player->pos.width / 2,
            player->pos.height / 2};
        if (CheckCollisionRecs(hitbox, level->one.black_box))
        {
            level->one.show_quiz = true;
        }
        else
            level->one.show_quiz = false;
    }
}

void DrawLevel(t_level level, t_player player)
{
    DrawRectangle(0, screen_height * 0.9, screen_width, screen_height, GRAY);
    DrawLineEx((Vector2){0, screen_height * 0.9}, (Vector2){screen_width, screen_height * 0.9}, 4, BLACK);
    switch (level.type)
    {
    case LEVEL_1:
        if (!level.one.hide_text)
        {
            for (int i = 0; i < 4; i++)
            {
                int textWidth = MeasureText(level.one.prologue_text[i], 40);
                DrawText(level.one.prologue_text[i], screen_width / 2 - textWidth / 2, screen_height / 3 + (i * 40), 40, BLACK);
            }
        }
        DrawRectangleRec(level.one.black_box, (Color){10, 10, 10, 255});
        if (level.one.show_quiz)
        {
            int quizWidth = 550;
            int quizHeight = 300;
            Rectangle quizRect = {screen_width / 2 - quizWidth / 2, screen_height / 2 - quizHeight / 2, quizWidth, quizHeight};
            DrawRectangleRec(quizRect, Fade((Color){30, 30, 30, 230}, 0.9f)); // semi-transparent dark rectangle

            // Draw the quiz inside the rectangle
            const char *quizText[] = {
                "Quiz:",
                "Lehilahy iray mijery sary.",
                "Nisy olona nanontany azy: \"Iza io?\"",
                "Namaly izy: \"Tsy manana anabavy sy rahalahy aho,",
                "fa ny dadan'io olona io dia zanaky ny dadako.\"",
                "Iza ilay amin'ny sary?"};
            for (int i = 0; i < 6; i++)
            {
                DrawText(quizText[i], quizRect.x + 10, quizRect.y + 10 + i * 40, 20, RAYWHITE);
            }

            // Definire la taille du bouton
            int buttonWidth = (quizWidth - 50) / 4;
            int buttonHeight = 40;
            int buttonY = quizRect.y + quizHeight - buttonHeight - 20;

            const char *choices[] = {"A", "B", "C", "D"};
            for (int i = 0; i < 4; i++)
            {
                Rectangle btn = {
                    quizRect.x + 10 + i * (buttonWidth + 10),
                    buttonY,
                    buttonWidth,
                    buttonHeight};

                bool hovered = CheckCollisionPointRec((Vector2){mouseX, mouseY}, btn);

                DrawRectangleRec(btn, hovered ? SKYBLUE : DARKGRAY);
                DrawRectangleLinesEx(btn, 2, RAYWHITE);

                int letterWidth = MeasureText(choices[i], 30);
                DrawText(choices[i],
                         btn.x + btn.width / 2 - letterWidth / 2,
                         btn.y + btn.height / 2 - 15,
                         30,
                         RAYWHITE);
            }
        }
        break;
    case LEVEL_2:
        DrawText("LEVEL 2", 0, 0, 10, BLACK);
        break;
    case LEVEL_3:
        DrawText("LEVEL 3", 0, 0, 10, BLACK);
        break;
    }
    DrawPlayer(player);
}

void UnloadLevel(t_level *level)
{
    (void)level;
}

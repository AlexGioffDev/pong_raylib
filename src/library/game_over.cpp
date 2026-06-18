#include "game_over.hpp"
#include "game.hpp"
#include "raylib.h"

static const int MENU_NUM_OPTIONS = 2;
static const char *MENU_OPTIONS[MENU_NUM_OPTIONS] = {
    "Back to Menu",
    "Quit"};

Menu GameOverMenuCreate()
{
    Menu menu;
    menu.selectedOption = 0;
    return menu;
}

void GameOverUpdate(Menu &gameover, App &app)
{
    if (IsKeyPressed(KEY_UP))
    {
        gameover.selectedOption--;
        if (gameover.selectedOption < 0)
        {
            gameover.selectedOption = MENU_NUM_OPTIONS - 1;
        }
    }

    if (IsKeyPressed(KEY_DOWN))
    {
        gameover.selectedOption++;
        if (gameover.selectedOption >= MENU_NUM_OPTIONS)
        {
            gameover.selectedOption = 0;
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        switch (gameover.selectedOption)
        {
        case 0:
            app.game = STATE_MENU;
            break;

        case 1:
            app.game = STATE_QUIT;
            break;
        }
    }
}

void GameOverDraw(const Menu &gameOver, Winner winner)
{
    ClearBackground(RAYWHITE);

    const char *message;

    switch (winner)
    {
    case Winner::PLAYER:
        message = "You Win!";
        break;
    case Winner::PC:
        message = "You Lose!";
        break;
    }

    int titleFontSize = 60;
    int fontSize = 28;
    int paddingX = 40;
    int paddingY = 16;
    int spacing = 70;
    int titleMargin = 60;

    int rectHeight = fontSize + paddingY * 2;

    int totalHeight = titleFontSize + titleMargin + MENU_NUM_OPTIONS * rectHeight + (MENU_NUM_OPTIONS - 1) * (spacing - rectHeight);

    int blockStartY = (GetScreenHeight() - totalHeight) / 2;

    int titleWidth = MeasureText(message, titleFontSize);
    DrawText(message, (GetScreenWidth() - titleWidth) / 2, blockStartY, titleFontSize, BLACK);

    int startY = blockStartY + titleFontSize + titleMargin;

    for (int i = 0; i < MENU_NUM_OPTIONS; i++)
    {
        int textWidth = MeasureText(MENU_OPTIONS[i], fontSize);
        int rectWidth = textWidth + paddingX * 2;
        int posX = (GetScreenWidth() - rectWidth) / 2;
        int posY = startY + i * spacing;

        if (i == gameOver.selectedOption)
        {
            DrawRectangle(posX, posY, rectWidth, rectHeight, BLACK);
            DrawText(MENU_OPTIONS[i], posX + paddingX, posY + paddingY, fontSize, WHITE);
        }
        else
        {
            DrawText(MENU_OPTIONS[i], posX + paddingX, posY + paddingY, fontSize, BLACK);
        }
    }
}
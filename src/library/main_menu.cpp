#include "main_menu.hpp"
#include "raylib.h"

static const int MENU_NUM_OPTIONS = 2;
static const char *MENU_OPTIONS[MENU_NUM_OPTIONS] = {
    "New Game",
    "Quit"};

Menu MenuCreate()
{
    Menu menu;
    menu.selectedOption = 0;
    return menu;
}

void MenuUpdate(Menu &menu, App &app)
{
    if (IsKeyPressed(KEY_UP))
    {
        menu.selectedOption--;
        if (menu.selectedOption < 0)
        {
            menu.selectedOption = MENU_NUM_OPTIONS - 1;
        }
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        menu.selectedOption++;
        if (menu.selectedOption >= MENU_NUM_OPTIONS)
        {
            menu.selectedOption = 0;
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        switch (menu.selectedOption)
        {
        case 0:
            app.game = STATE_GAME;  
            break;
        case 1:
            app.game = STATE_QUIT;  
            break;
        }
    }
}

void MenuDraw(const Menu &menu, int screenWidth, int screenHeight)
{
    ClearBackground(RAYWHITE);

    int titleFontSize = 60;
    int fontSize = 28;
    int paddingX = 40;
    int paddingY = 16;
    int spacing = 70;
    int titleMargin = 60; 

    int rectHeight = fontSize + paddingY * 2;

    int totalHeight = titleFontSize + titleMargin + MENU_NUM_OPTIONS * rectHeight + (MENU_NUM_OPTIONS - 1) * (spacing - rectHeight);

    int blockStartY = (screenHeight - totalHeight) / 2;

    const char *title = "Pong";
    int titleWidth = MeasureText(title, titleFontSize);
    DrawText(title, (screenWidth - titleWidth) / 2, blockStartY, titleFontSize, BLACK);

    int startY = blockStartY + titleFontSize + titleMargin;

    for (int i = 0; i < MENU_NUM_OPTIONS; i++)
    {
        int textWidth = MeasureText(MENU_OPTIONS[i], fontSize);
        int rectWidth = textWidth + paddingX * 2;
        int posX = (screenWidth - rectWidth) / 2;
        int posY = startY + i * spacing;

        if (i == menu.selectedOption)
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
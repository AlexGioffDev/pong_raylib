
#include "raylib.h"
#include "game_state.hpp"
#include "main_menu.hpp"
#include "game_over.hpp"
#include "game.hpp"

int main()
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "Esempio di Disegno");

    SetTargetFPS(60);

    App app;
    app.game = STATE_MENU;
    Menu menu = MenuCreate();
    Menu gameOver = GameOverMenuCreate();
    Game game = GameCreate(GetScreenWidth(), GetScreenHeight());
    Winner winner = Winner::NONE;

    while (!WindowShouldClose() && app.game != STATE_QUIT)
    {
        // SetExitKey(0);

        switch (app.game)
        {
        case STATE_MENU:
        {
            GAME_STATE prev = app.game;
            MenuUpdate(menu, app);
            if (prev != app.game && app.game == STATE_GAME)
            {
                GameReset(game, GetScreenWidth(), GetScreenHeight());
            }
            break;
        }
        case STATE_GAME:
        {
            float deltaTime = GetFrameTime();
            GameUpdate(game, deltaTime, GetScreenHeight(), GetScreenWidth());

            if (GameIsOver(game))
            {
                winner = GameGetWinner(game);
                app.game = STATE_GAMEOVER;
            }

            break;
        }
        case STATE_GAMEOVER:
        {
            GAME_STATE prev = app.game;
            GameOverUpdate(gameOver, app);
            if (prev != app.game && app.game == STATE_GAME)
            {
                GameReset(game, GetScreenWidth(), GetScreenHeight());
            }
            break;
        }
        case STATE_QUIT:
            break;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (app.game)
        {
        case STATE_MENU:
            MenuDraw(menu, GetScreenWidth(), GetScreenHeight());
            break;

        case STATE_GAME:
        {
            ClearBackground(BLACK);
            GameDraw(game, GetScreenHeight(), GetScreenWidth());
            break;
        }
        case STATE_GAMEOVER:
        {
            GameOverDraw(gameOver, winner);
            break;
        }
        case STATE_QUIT:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
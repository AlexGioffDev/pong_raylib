
#include "raylib.h"
#include "game_state.hpp"
#include "main_menu.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "Scoreboard.hpp"


int main()
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "Esempio di Disegno");

    SetTargetFPS(60);

    App app;
    app.game = STATE_MENU;
    Menu menu = MenuCreate();

    Paddle playerPaddle = PaddleCreate(30, GetScreenHeight() / 2 - 50, 300, 60, 300);
    Paddle aiPaddle = PaddleCreate(GetScreenWidth() - 90, GetScreenHeight() / 2 - 50, 450, 60, 300);

    Ball ball = BallCreate(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 30);
    ScoreBoard scoreboad = ScoreBoardInit();



    while (!WindowShouldClose() && app.game != STATE_QUIT)
    {
        // SetExitKey(0);

        switch (app.game)
        {
        case STATE_MENU:
            MenuUpdate(menu, app);
            break;

        case STATE_GAME:
        {
            float deltaTime = GetFrameTime();
            PaddleUpdatePlayer(playerPaddle, deltaTime, GetScreenHeight());
            PaddleUpdateAI(aiPaddle, ball.pos.y, ball.dirX,deltaTime, GetScreenHeight());

            Rectangle playerRect = {playerPaddle.position.x, playerPaddle.position.y, playerPaddle.width, playerPaddle.height};
            Rectangle aiRect = {aiPaddle.position.x, aiPaddle.position.y, aiPaddle.width, aiPaddle.height};

            BallEvent ballEvent = BallUpdate(ball, deltaTime, GetScreenHeight(), playerRect, aiRect, playerPaddle.position.x, aiPaddle.position.x);

            if (ballEvent == BallEvent::PLAYER_SCORE)
            {
                ScoreUser(scoreboad);
                BallReset(ball);
            }

            if (ballEvent == BallEvent::PC_SCORE)
            {
                ScorePc(scoreboad);
                BallReset(ball);
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
            ScoreBoardDraw(scoreboad);
            DrawText("Press ESC to close the game", GetScreenWidth() - MeasureText("Press ESCO To close the game", 14), GetScreenHeight() - 40, 14, RAYWHITE);
            PaddleDraw(playerPaddle);
            PaddleDraw(aiPaddle);
            BallDraw(ball);
            break;
        }
        case STATE_QUIT:
            break;
        }

        EndDrawing();
    }

    // Eventuale cleanup
    // MenuDestroy(menu);

    CloseWindow();
    return 0;
}
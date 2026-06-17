#include "paddle.hpp"

Paddle PaddleCreate(float x, float y, float speed, float width, float height)
{
    Paddle paddle;
    paddle.position = {x, y};
    paddle.speed = speed;
    paddle.width = width;
    paddle.height = height;
    return paddle;
}

void PaddleDraw(const Paddle &paddle)
{
    DrawRectangle(paddle.position.x, paddle.position.y, paddle.width, paddle.height, RAYWHITE);
}

void PaddleUpdatePlayer(Paddle &paddle, float deltaTime, float screenHeight)
{
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        paddle.position.y -= paddle.speed * deltaTime;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        paddle.position.y += paddle.speed * deltaTime;
    }

    if (paddle.position.y < 0)
    {
        paddle.position.y = 0;
    }
    if (paddle.position.y > screenHeight - paddle.height)
    {
        paddle.position.y = screenHeight - paddle.height;
    }
}

void PaddleUpdateAI(Paddle &paddle, float ballY, float deltaTime, float screenHeight)
{
    if(paddle.position.y > ballY)
    {
        paddle.position.y -= paddle.speed * deltaTime;
    } else if(paddle.position.y < ballY)
    {
        paddle.position.y += paddle.speed * deltaTime;
    }
}
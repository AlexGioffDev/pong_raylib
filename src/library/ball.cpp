#include "ball.hpp"
#include <cmath>

Ball BallCreate(float x, float y, float ratio)
{
    Ball ball;
    ball.pos.x = x;
    ball.pos.y = y;
    ball.ratios = ratio;
    ball.speed = 450.0f;

    ball.dirX = -1.0f;
    ball.dirY = 1.0;

    return ball;
}

void BallDraw(const Ball &ball)
{
    DrawCircle(ball.pos.x, ball.pos.y, ball.ratios, WHITE);
}

BallEvent BallUpdate(Ball &ball, float deltatime, float screenHeight, Rectangle playerRect, Rectangle pcRect, float playerX, float pcX)
{
    if (CheckCollisionCircleRec(ball.pos, ball.ratios, playerRect))
    {
        float paddleCenterY = playerRect.y + playerRect.height / 2.0f;
        float hitFactor = (ball.pos.y - paddleCenterY) / (playerRect.height / 2.0f);
        
        ball.dirX = 1.0f;
        ball.dirY = hitFactor; 

        float length = std::sqrt(ball.dirX * ball.dirX + ball.dirY * ball.dirY);
        ball.dirX /= length;
        ball.dirY /= length;

        ball.pos.x = playerX + playerRect.width + ball.ratios;
        ball.speed *= 1.15f; 
        if(ball.speed > 1100.0f) ball.speed = 1100.0f;
    }

    if (CheckCollisionCircleRec(ball.pos, ball.ratios, pcRect))
    {
        float paddleCenterY = pcRect.y + pcRect.height / 2.0f;
        float hitFactor = (ball.pos.y - paddleCenterY) / (pcRect.height / 2.0f);
        
        ball.dirX = -1.0f;
        ball.dirY = hitFactor;

        float length = std::sqrt(ball.dirX * ball.dirX + ball.dirY * ball.dirY);
        ball.dirX /= length;
        ball.dirY /= length;

        ball.pos.x = pcX - ball.ratios;
        ball.speed *= 1.15f;
        if(ball.speed > 1100.0f) ball.speed = 1100.0f; 
    }

    if (ball.pos.y - ball.ratios < 0)
    {
        ball.dirY = std::abs(ball.dirY); 
        ball.pos.y = ball.ratios;
    }

    if (ball.pos.y + ball.ratios > screenHeight)
    {
        ball.dirY = -std::abs(ball.dirY);
        ball.pos.y = screenHeight - ball.ratios;
    }

    if (ball.pos.x - ball.ratios < 0) return BallEvent::PC_SCORE;
    if (ball.pos.x + ball.ratios > GetScreenWidth()) return BallEvent::PLAYER_SCORE;

    ball.pos.x += ball.dirX * ball.speed * deltatime;
    ball.pos.y += ball.dirY * ball.speed * deltatime;

    return BallEvent::NONE;
}

void BallReset(Ball &ball)
{
    ball.pos.x = GetScreenWidth() / 2.0f;
    ball.pos.y = GetScreenHeight() / 2.0f;
    ball.speed = 450.0f;

    ball.dirX *= -1.0f;
    ball.dirY = (GetRandomValue(0, 1) == 0) ? 1.0f : -1.0f;

}
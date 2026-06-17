#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "raylib.h"

struct Ball
{
    Vector2 pos;
    float ratios;
    float speed;
    float dirX;
    float dirY;

};

enum class BallEvent
{
    NONE,
    PLAYER_SCORE,
    PC_SCORE
};

Ball BallCreate(float x, float y, float ratio);

void BallDraw(const Ball& ball);

BallEvent BallUpdate(Ball& ball, float deltatime, float screenHeight, Rectangle playerRect, Rectangle pcRect, float playerX, float pcX);

void BallReset(Ball& ball);

#endif // __BALL_HPP__
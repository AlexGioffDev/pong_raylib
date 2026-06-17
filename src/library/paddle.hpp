#ifndef __PADDLE_HPP__
#define __PADDLE_HPP__

#include "raylib.h"

struct Paddle
{
    Vector2 position;
    float speed;
    float width;
    float height;
};


Paddle PaddleCreate(float x, float y, float speed, float width, float height);
void PaddleDraw(const Paddle &paddle);

void PaddleUpdatePlayer(Paddle &paddle, float deltaTime, float screenHeight);

void PaddleUpdateAI(Paddle &paddle, float ballY, float ballDirX,float deltaTime, float screenHeight);


#endif // __PADDLE_HPP__
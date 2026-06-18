#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "paddle.hpp"
#include "ball.hpp"
#include "Scoreboard.hpp"

enum class Winner
{
    NONE,
    PLAYER,
    PC
}; 

struct Game
{
    Paddle player;
    Paddle pc;
    Ball ball;
    ScoreBoard scoreboard;
    int maxScore;
};

Game GameCreate(int screenWidth, int screenHeight);
void GameUpdate(Game &game,float deltatime, int screenHeight, int screenWidth);
void GameDraw(const Game &game, int screenHeight, int screenWidth);
bool GameIsOver(const Game& game);
void GameReset(Game &game, int screenWidth, int screenHeight);
Winner GameGetWinner(const Game& game);

#endif // __GAME_HPP__
#include "game.hpp"

Game GameCreate(int screenWidth, int screenHeight)
{
    Game game;
    game.player = PaddleCreate(30, screenHeight / 2 - 50, 300, 60, 300);
    game.pc = PaddleCreate(screenWidth - 90, screenHeight / 2 - 50, 450, 60, 300);
    game.ball = BallCreate(screenWidth / 2.0f, screenHeight / 2.0f, 30);
    game.maxScore = 1;
    game.scoreboard = ScoreBoardInit();
    return game;
}

void GameUpdate(Game &game, float deltatime, int screenHeight, int screenWidth)
{
    PaddleUpdatePlayer(game.player, deltatime, screenHeight);
    PaddleUpdateAI(game.pc, game.ball.pos.y, game.ball.dirX, deltatime, screenHeight);
    Rectangle playerRect = {game.player.position.x, game.player.position.y, game.player.width, game.player.height};
    Rectangle aiRect = {game.pc.position.x, game.pc.position.y, game.pc.width, game.pc.height};

    BallEvent event = BallUpdate(game.ball, deltatime, GetScreenHeight(), playerRect, aiRect, game.player.position.x, game.pc.position.x);

    if(event == BallEvent::PLAYER_SCORE)
    {
        ScoreUser(game.scoreboard);
        BallReset(game.ball);
    }

    if(event == BallEvent::PC_SCORE)
    {
        ScorePc(game.scoreboard);
        BallReset(game.ball);
    }


}

void GameDraw(const Game& game, int screenHeight, int screenWidth)
{
    ScoreBoardDraw(game.scoreboard);
    PaddleDraw(game.player);
    PaddleDraw(game.pc);
    BallDraw(game.ball);
}


bool GameIsOver(const Game& game)
{
    if(game.scoreboard.scorePc == game.maxScore)
    {
        return true;
    }

    if(game.scoreboard.scoreUser == game.maxScore)
    {
        return true;
    }

    return false;
}

void GameReset(Game &game, int screenWidth, int screenHeight)
{
    game.player = PaddleCreate(30, screenHeight / 2 - 50, 300, 60, 300);
    game.pc = PaddleCreate(screenWidth - 90, screenHeight / 2 - 50, 450, 60, 300);
    game.ball = BallCreate(screenWidth / 2.0f, screenHeight / 2.0f, 30);

    game.scoreboard = ScoreBoardInit();
}

Winner GameGetWinner(const Game& game)
{
    if(game.scoreboard.scoreUser == game.maxScore) return Winner::PLAYER;
    if(game.scoreboard.scorePc == game.maxScore) return Winner::PC; 
    return Winner::NONE;
}

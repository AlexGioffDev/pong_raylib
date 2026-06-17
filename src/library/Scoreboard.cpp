#include <iostream>
#include <string>
#include "raylib.h"
#include "Scoreboard.hpp"

using namespace std;

ScoreBoard ScoreBoardInit()
{
    ScoreBoard scoreboad;
    scoreboad.scorePc = 0;
    scoreboad.scoreUser = 0;
    return scoreboad;
}

void ScoreBoardDraw(const ScoreBoard& scoreboard)
{
    auto userScoreText = to_string(scoreboard.scoreUser);
    auto pcScoreText = to_string(scoreboard.scorePc);

    int fontSize = 120;
    int centerX = GetScreenWidth() / 2;
    int gap = 60;

    int textWidth = MeasureText(userScoreText.c_str(), fontSize);

    DrawLine(centerX, 0, centerX, GetScreenHeight(), GRAY);

    DrawText(userScoreText.c_str(), centerX - gap - textWidth, 20,fontSize, RAYWHITE );
    DrawText(pcScoreText.c_str(), centerX + gap, 20,fontSize, RAYWHITE );

}


void ScoreUser(ScoreBoard& scoreboard)
{
    scoreboard.scoreUser++;
}


void ScorePc(ScoreBoard& scoreboard)
{
    scoreboard.scorePc++;
}
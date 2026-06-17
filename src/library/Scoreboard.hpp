#ifndef __SCOREBOARD_HPP__
#define __SCOREBOARD_HPP__

struct ScoreBoard
{
    int scoreUser;
    int scorePc;

};

ScoreBoard ScoreBoardInit();

void ScoreBoardDraw(const ScoreBoard& scoreboard);

void ScoreUser(ScoreBoard& scoreBoard);
void ScorePc(ScoreBoard& scoreBoard);

#endif // __SCOREBOARD_HPP__
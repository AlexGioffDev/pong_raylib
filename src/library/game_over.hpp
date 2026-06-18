#ifndef __GAMEOVER_HPP__
#define __GAMEOVER_HPP__
#include "game_state.hpp"
#include "game.hpp"
#include "menu.hpp"

Menu GameOverMenuCreate();
void GameOverUpdate(Menu& gameover, App& app);
void GameOverDraw(const Menu& gameOver, Winner winner);

#endif // __GAMEOVER_HPP__
#pragma once

enum GAME_STATE
{
    STATE_MENU,
    STATE_GAME,
    STATE_QUIT
};

struct App
{
    GAME_STATE game;
};
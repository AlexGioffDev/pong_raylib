#ifndef __MAIN_MENU_HPP__
#define __MAIN_MENU_HPP__
#include "game_state.hpp"
#include "menu.hpp"

Menu MenuCreate();
void MenuUpdate(Menu &menu, App &app);
void MenuDraw(const Menu &menu, int screenWidth, int screenHeight); 

#endif // __MAIN_MENU_HPP__
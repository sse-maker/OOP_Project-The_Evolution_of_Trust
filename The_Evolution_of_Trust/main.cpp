//
//  main.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Game.hpp"

int main() {
    Game *game = new Game;
    game->Run();
    delete game;
}

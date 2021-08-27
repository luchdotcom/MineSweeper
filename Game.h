//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_GAME_H
#define MS_21_04_GAME_H



#include <iostream>
#include <typeinfo>
#include "Enemy.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <windows.h>

class Game: public CEnemy{
public:
    Game(const CBoard &, const CPlayer &, bool=false, bool=false);
    ~Game();
    int drawBoard() const;
    int playGame();
private:
    CBoard b;
    CPlayer p;
    bool mark, open;
    unsigned row, col;

};


#endif //MS_21_04_GAME_H

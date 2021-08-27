//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_BOARD_H
#define MS_21_04_BOARD_H


#include <iostream>
#include <cstdlib>
#include <typeinfo>

#include "Enemy.h"
#include "DeadlyEnemy.h"
#include "SuperDeadlyEnemy.h"
//#include <stdexcept>
#include "PowerError.h"

class CBoard{
public:
    CBoard();
    CBoard(unsigned);
    CBoard(unsigned, unsigned);
    CBoard(unsigned, unsigned, unsigned);//add this
    ~CBoard();//change here
    CBoard(const CBoard&);//change here
    CBoard& operator=(const CBoard &);//change here
    int createBoard(unsigned, unsigned, unsigned);
    int createBoardWithEnemys(unsigned, unsigned, unsigned);
    std::ostream& ins(std::ostream&) const;
    std::istream& ext(std::istream&);  ///// check
    int operator()(unsigned, unsigned) const;
    int markBoard(unsigned, unsigned);
    int openBoard(unsigned, unsigned);
    bool isEnemy(unsigned, unsigned) const;

    unsigned setR(unsigned );///// check
    unsigned setC(unsigned );///// check
    unsigned setCnt_enemy(unsigned );///// check
    unsigned getR() const;
    unsigned getC() const;
private:
    int ** viewBoard;
    int ** checkBoard;
    unsigned c, r;
    unsigned cnt_enemy;
    CEnemy ** enemys;//dynamic array of pointers
};

std::ostream& operator<<(std::ostream &, const CBoard &);
std::istream& operator>>(std::istream &, CBoard & );///// check



#endif //MS_21_04_BOARD_H

//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_SUPERDEADLYENEMY_H
#define MS_21_04_SUPERDEADLYENEMY_H


#include <iostream>
#include "DeadlyEnemy.h"

class SuperDeadlyEnemy: public DeadlyEnemy{
public:
    SuperDeadlyEnemy();
    SuperDeadlyEnemy(unsigned, char, int, int, unsigned, int);
    SuperDeadlyEnemy(const SuperDeadlyEnemy&);
    virtual ~SuperDeadlyEnemy();
    SuperDeadlyEnemy& operator=(const SuperDeadlyEnemy &);
    virtual std::ostream& ins(std::ostream &)const;
    virtual std::istream& ext(std::istream &);
    virtual int poison(CPlayer &)const;
private:
    int multyPower;
};



#endif //MS_21_04_SUPERDEADLYENEMY_H

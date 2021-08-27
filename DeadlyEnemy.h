//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_DEADLYENEMY_H
#define MS_21_04_DEADLYENEMY_H


#include <iostream>
#include "Enemy.h"

class DeadlyEnemy:public CEnemy{
public:
    DeadlyEnemy();
    DeadlyEnemy(unsigned, char, int, int, unsigned);
    DeadlyEnemy(const DeadlyEnemy &);
    virtual ~DeadlyEnemy();
    DeadlyEnemy& operator=(const DeadlyEnemy &);
    //hw set and get
    int getSound() const;
    int getDuration() const;
    unsigned getPower() const;
    int setSound(int);
    int setDuration(int);
    virtual int setPower(unsigned);

    virtual std::ostream& ins(std::ostream&) const;
    virtual std::istream& ext(std::istream&);
    virtual int poison(CPlayer &)const;
private:
    int sound;
    int duration;
    unsigned power;
};



#endif //MS_21_04_DEADLYENEMY_H

//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_ENEMY_H
#define MS_21_04_ENEMY_H


#include<cstdlib>
#include<iostream>
#include "Player.h"

class CEnemy {
public:
    CEnemy();
    CEnemy(unsigned);
    CEnemy(unsigned, char);
    virtual ~CEnemy();

    int setCount(unsigned);
    int setIcon(char);

    unsigned getCount() const;
    char getIcon() const;
    //enemy1+enemy2
    CEnemy operator+(const CEnemy &);
    virtual std::ostream& ins(std::ostream&) const;
    virtual std::istream& ext(std::istream&);
    virtual int poison(CPlayer &)const;
private:
    unsigned count;
    char icon;
};

//cout << enemy;
std::ostream& operator<<(std::ostream&, const CEnemy &);
std::istream& operator>>(std::istream&, CEnemy&);



#endif //MS_21_04_ENEMY_H

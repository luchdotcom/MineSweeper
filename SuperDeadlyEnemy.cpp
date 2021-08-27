//
// Created by Lachezar on 21.4.2020 г..
//

#include "SuperDeadlyEnemy.h"

SuperDeadlyEnemy::SuperDeadlyEnemy(){}

SuperDeadlyEnemy::SuperDeadlyEnemy(unsigned count, char icon, int sound, int duration, unsigned power, int multyPower):
        DeadlyEnemy(count, icon, sound, duration, power), multyPower(multyPower) {
    setPower(power*multyPower);
}

SuperDeadlyEnemy::SuperDeadlyEnemy(const SuperDeadlyEnemy& rhs):DeadlyEnemy(rhs){
    multyPower = rhs.multyPower;
}

SuperDeadlyEnemy::~SuperDeadlyEnemy(){}

SuperDeadlyEnemy& SuperDeadlyEnemy::operator=(const SuperDeadlyEnemy & rhs){
    if(this!=&rhs){
        DeadlyEnemy::operator=(rhs);
        multyPower = rhs.multyPower;
    }
    return *this;
}

std::ostream& SuperDeadlyEnemy::ins(std::ostream & out)const{
    DeadlyEnemy::ins(out);
    return out << std::endl << "multiply power: " << multyPower << std::endl;
}

std::istream& SuperDeadlyEnemy::ext(std::istream & in){
    DeadlyEnemy::ext(in);
    return in >> multyPower;
}

int SuperDeadlyEnemy::poison(CPlayer & p)const{
    p.setState(false);
    p.setLives(0);
    p.setScore(p.getScore()-10);
    return 0;
}

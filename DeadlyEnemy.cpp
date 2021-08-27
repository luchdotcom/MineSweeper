//
// Created by Lachezar on 21.4.2020 г..
//

#include "DeadlyEnemy.h"
#include "PowerError.h"

DeadlyEnemy::DeadlyEnemy():CEnemy(), sound(500), duration(1000), power(2){}

DeadlyEnemy::DeadlyEnemy(unsigned count, char icon, int sound, int duration, unsigned power):
        CEnemy(count, icon), sound(sound), duration(duration), power(power){
    if (power>10){
        throw PowerError("Enemy whit power more than ",0,10);
    }
}

DeadlyEnemy::DeadlyEnemy(const DeadlyEnemy & rhs):CEnemy(rhs){
    sound = rhs.sound;
    duration = rhs.duration;
    power = rhs.power;
}

DeadlyEnemy::~DeadlyEnemy(){
    std::cout << "DeadlyEnemy destructor called!\n";
}

DeadlyEnemy& DeadlyEnemy::operator=(const DeadlyEnemy & rhs){
    if(this!=&rhs){
        CEnemy::operator=(rhs);
        sound = rhs.sound;
        duration = rhs.duration;
        power = rhs.power;
    }
    return *this;
}


int DeadlyEnemy::getSound() const{
    return sound;
}

int DeadlyEnemy::getDuration() const{
    return duration;
}

unsigned DeadlyEnemy::getPower() const{
    return power;
}

int DeadlyEnemy::setSound(int sound){
    this->sound = sound;
    return 0;
}

int DeadlyEnemy::setDuration(int duration){
    this->duration = duration;
    return 0;
}

int DeadlyEnemy::setPower(unsigned power){
    if (power>10){
        throw PowerError("Too strong enemy is not possible to be made ",0,15);
    }
    this->power = power;

    return 0;
}

std::ostream& DeadlyEnemy::ins(std::ostream& out) const{
    CEnemy::ins(out);
    return out << "sound: " << sound << std::endl
               << "Duration: " << duration << std::endl
               << "Power: " << power << std::endl;

}
std::istream& DeadlyEnemy::ext(std::istream& in){
    CEnemy::ext(in);
    in >> sound >> duration >> power;
    return in;
}

int DeadlyEnemy::poison(CPlayer & p)const{
    p.setState(false);
    p.setLives(p.getLives()-1);
    return 0;
}

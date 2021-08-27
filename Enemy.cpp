//
// Created by Lachezar on 21.4.2020 г..
//

#include "Enemy.h"

CEnemy::CEnemy() {
    std::cout << "Default constructor called here!\n";
    count = rand()%10+1;
    icon = '@';
}


CEnemy::CEnemy(unsigned count):count(count), icon('*'){
    if (count <3 || count>20){
        throw std::out_of_range("enemy in not correctly initialise ");
    }
}

CEnemy::CEnemy(unsigned count, char icon):count(count), icon(icon) {
    if (count <3 || count>20){
        throw std::out_of_range("enemy in not correctly initialise ");
    }
    std::cout << "Constructor with parameters is called here!\n";
}

/*CEnemy::CEnemy(unsigned count, char icon) {
 if(count!=0)
 this->count = count;
 else
 this->count = 1;
 this->icon = icon;
 }*/

CEnemy::~CEnemy() {
    std::cout << "Destructor called here!\n";
}

int CEnemy::setCount(unsigned count) {
    this->count = count;
    return 0;
}

int CEnemy::setIcon(char icon) {
    this->icon = icon;
    return 0;
}

unsigned CEnemy::getCount() const {
    if (count <3 || count>20){
        throw std::out_of_range("enemy in not correctly initialise ");
    }

    return count;
}

char CEnemy::getIcon() const {
    return icon;
}

std::ostream& CEnemy::ins(std::ostream& out) const{
    return out << "Count: " << count << std::endl
               << "Icon: " << icon << std::endl;

}
std::istream& CEnemy::ext(std::istream& in){
    unsigned cnt;
    char i;
    in >> cnt >> i;
    setCount(cnt);
    setIcon(i);
    return in;
}

int CEnemy::poison(CPlayer & p)const{
    p.setState(false);
    return 0;
}

std::ostream& operator<<(std::ostream& out, const CEnemy & rhs){
    return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, CEnemy& rhs){
    return rhs.ext(in);
}

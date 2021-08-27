//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_PLAYER_H
#define MS_21_04_PLAYER_H


#include <cstring>
#include <iostream>
#include <stdexcept>


//<<
class CPlayer {
public:
    CPlayer();
    CPlayer(const char *);
    CPlayer(unsigned, unsigned, bool, const char*);
    CPlayer(bool, const char*);
    CPlayer(const CPlayer &);

    CPlayer& operator=(const CPlayer&);

    ~CPlayer();

    int setScore(unsigned);
    int setLives(unsigned);
    int setState(bool);
    int setNick(const char *);

    unsigned getScore() const;
    unsigned getLives() const;
    bool getState() const;
    char * getNick() const;

    int print() const;

    std::ostream& ins(std::ostream&) const;
    std::istream& ext(std::istream&);

private:
    unsigned score;
    unsigned lives;
    bool state;
    char * nick;
};
//cout<<obj;
std::ostream& operator<<(std::ostream &, const CPlayer&);

//cin >> obj >> obj2 >> obj3;
std::istream& operator>>(std::istream &, CPlayer &);



#endif //MS_21_04_PLAYER_H

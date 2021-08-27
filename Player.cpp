//
// Created by Lachezar on 21.4.2020 г..
//

#include "Player.h"


CPlayer::CPlayer():score(0), lives(2), state(true),
                   nick(new char[10]){
    strcpy(nick, "Goshoko");
}

CPlayer::CPlayer(const char * nick):score(0), lives(2), state(true),
                                    nick(new char[strlen(nick)+1]){
    strcpy(this->nick, nick);
}

CPlayer::CPlayer(unsigned score, unsigned lives,
                 bool state, const char* nick): nick(new char[strlen(nick) + 1]) {

    this->score = score;
    if (score !=0) {throw std::out_of_range("Player is initialized whit score greater than  0!!!");}
    this->lives = lives;
    this->state = state;
    if (state == false && lives>0  ){
        throw std::logic_error("Player is not possible to be initialize whit lives and without state");
    }
    strcpy(this->nick, nick);
}

CPlayer::CPlayer(bool state, const char* nick):score(0), lives(2),
                                               nick(new char[strlen(nick) + 1]) {
    strcpy(this->nick, nick);
    this->state = (!state) ? true : state;
}

CPlayer::CPlayer(const CPlayer & rhs):score(rhs.score),
                                      lives(rhs.lives), state(rhs.state),
                                      nick(new char[strlen(rhs.nick)+1]){
    strcpy(nick, rhs.nick);
}

CPlayer& CPlayer::operator=(const CPlayer & rhs){
    if (this != &rhs) {
        /*if (nick != nullptr) {
         delete[] nick;
         nick = nullptr;
         }
         nick = new char[strlen(rhs.nick) + 1];
         strcpy_s(nick, strlen(rhs.nick) + 1, rhs.nick);*/
        this->setNick(rhs.nick);
        score = rhs.score;
        lives = rhs.lives;
        state = rhs.state;
    }
    return *this;
}

CPlayer::~CPlayer(){
    if (nick != NULL) {
        delete[] nick;
        nick = NULL;
    }
}

int CPlayer::setScore(unsigned score){
    this->score = score;
    return 0;
}

int CPlayer::setLives(unsigned lives){
    this->lives = lives;
    return 0;
}

int CPlayer::setState(bool state){
    if (!state && lives == 0) this->state = state;
    else this->state = state;
    return 0;
}

int CPlayer::setNick(const char * nick){
    if (this->nick != NULL) {
        delete[] this->nick;
        this->nick = NULL;
    }
    this->nick = new char[strlen(nick) + 1];
    strcpy(this->nick, nick);

    return 0;
}

unsigned CPlayer::getScore() const{
    return score;
}

unsigned CPlayer::getLives() const{
    return lives;
}

bool CPlayer::getState() const{
    return state;
}

char * CPlayer::getNick() const{
    return nick;
}

int CPlayer::print() const {
    std::cout << "Nick: " << nick << std::endl;
    std::cout << "Lives: " << lives << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "State: " << (state?":-P":":-(") << std::endl;
    return 0;
}

std::ostream& CPlayer::ins(std::ostream& out) const{
    return out << "Nick: " << nick << std::endl
               << "Lives: " << lives << std::endl
               << "Score: " << score << std::endl
               << "State: " << (state?":-P":":-(") << std::endl;
}

std::istream& CPlayer::ext(std::istream& in){
    char * name = new char[30];
    in >> name;
    setNick(name);
    in >> lives >> score >> state;
    if(name!=NULL){
        delete[] name;
        name = NULL;
    }
    return in;
}

std::ostream& operator<<(std::ostream & out, const CPlayer& rhs){
    return rhs.ins(out);
}



std::istream& operator>>(std::istream & in, CPlayer & rhs){
    return rhs.ext(in);
}

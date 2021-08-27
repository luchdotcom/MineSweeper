//
// Created by Lachezar on 21.4.2020 г..
//

#include "Board.h"


CBoard::CBoard():r(5), c(5), viewBoard(new int*[5]), checkBoard(new int*[5]){
    for (int i=0; i<r; i++) {
        viewBoard[i] = new int[c];
        checkBoard[i] = new int[c];
    }
}

CBoard::CBoard(unsigned r):r(r), c(5), viewBoard(new int*[5]), checkBoard(new int*[5]){
    for (int i=0; i<r; i++) {
        viewBoard[i] = new int[c];
        checkBoard[i] = new int[c];
    }
}

CBoard::CBoard(unsigned r, unsigned c){}
CBoard::CBoard(unsigned, unsigned, unsigned){

}
CBoard::~CBoard(){
    if(viewBoard!= nullptr){
        for (int i=0; i<r; i++) {
            delete[] viewBoard[i];
        }
        delete [] viewBoard;
        viewBoard= nullptr;
    }

    if(checkBoard!= nullptr){
        for (int i=0; i<r; i++) {
            delete[] checkBoard[i];
        }
        delete [] checkBoard;
        checkBoard= nullptr;
    }
}

CBoard:: CBoard(const CBoard& rhs):viewBoard(new int*[rhs.r]), checkBoard(new int*[rhs.r]),
                                  r(rhs.r), c(rhs.c), cnt_enemy(rhs.cnt_enemy), enemys(new CEnemy*[rhs.cnt_enemy]) {
    for ( int i = 0; i < r; i++ ) {
        viewBoard[i] = new int[c];
        checkBoard[i] = new int[c];
    }
    for ( int i = 0; i < r; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            viewBoard[i][j] = rhs.viewBoard[i][j];
            checkBoard[i][j] = rhs.checkBoard[i][j];
        }
    }
        for ( int i = 0; i < cnt_enemy; i++ ) {
            enemys[i] = rhs.enemys[i];

    }
}
CBoard& CBoard::operator=(const CBoard & rhs) {
    if (this != &rhs) {
        if (viewBoard != nullptr) {
            for ( int i = 0; i < this->r; i++ ) {
                delete[] viewBoard[i];
            }
            delete[] viewBoard;
        }
        if (checkBoard != nullptr) {
            for ( int i = 0; i < this->r; i++ ) {
                delete[] checkBoard[i];
            }
            delete[] checkBoard;
        }
        this->r = rhs.r;
        this->c = rhs.c;
        this->cnt_enemy = rhs.cnt_enemy;
        viewBoard = new int *[r];
        checkBoard = new int *[r];
        for ( int i = 0; i < r; i++ ) {
            viewBoard[i] = new int[c]{0};
            checkBoard[i] = new int[c]{0};
        }
        for ( int i = 0; i < r; i++ ) {
            for ( int j = 0; j < c; j++ ) {
                viewBoard[i][j] = rhs.viewBoard[i][j];
                checkBoard[i][j] = rhs.checkBoard[i][j];
            }
        }
        if (enemys != nullptr) {
            for ( int i = 0; i < cnt_enemy; i++ ) {
                delete enemys[i];
            }
            delete[] enemys;
        }
        this->cnt_enemy = rhs.cnt_enemy;

        //polimorfic container
        enemys = new CEnemy *[cnt_enemy];

        for ( int i = 0; i < cnt_enemy; i++ ) {
            enemys[i] = rhs.enemys[i];
        }
    }

    return *this;
}

int CBoard::createBoard(unsigned r, unsigned c, unsigned cnt){
    if(viewBoard!= nullptr){
        for (int i=0; i<this->r; i++) {
            delete[] viewBoard[i];
        }
        delete [] viewBoard;
    }
    if(checkBoard!= nullptr){
        for (int i=0; i<this->r; i++) {
            delete[] checkBoard[i];
        }
        delete [] checkBoard;
    }
    this->r = r;
    this->c = c;
    try {
        this->cnt_enemy = cnt;
        throw std::out_of_range("element be create in <3 or <20 enemy");
    } catch (const std::out_of_range& ex) {
        std::cerr<<typeid(ex).name()<<ex.what();
        if (cnt<3){
            cnt=3;
        } else if (cnt>20){
            cnt=20;
        }
    }
    catch (...) {
        std::cerr<<"Some another exceptions ";
    }

    viewBoard = new int*[r];
    checkBoard = new int*[r];
    for (int i=0; i<r; i++) {
        viewBoard[i] = new int[c]{0};
        checkBoard[i] = new int[c]{0};
    }

    unsigned enemyOnField = 0, randR, randC;

    while(enemyOnField<cnt_enemy){
        //[0, r-1]
        randR = rand()%(r-1-0+1)+0;
        //[0, c-1]
        randC = rand()%c;
        if(viewBoard[randR][randC] == 0){
            viewBoard[randR][randC] = -1;
            enemyOnField++;
        }
    }
    enemyOnField = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if(viewBoard[i][j]==-1){
                for(int ii=((i==0)?i:i-1); ii<((i==r-1)?i+1:i+2); ii++){

                    for(int jj=((j==0)?j:(j-1)); jj<((j==c-1)?j+1:j+2); jj++){
                        if(viewBoard[ii][jj]!=-1){
                            viewBoard[ii][jj]++;
                        }
                    }
                }
                enemyOnField++;
            }
            if(enemyOnField==cnt_enemy){
                return 0;
            }
        }
    }


    return 0;
}


int CBoard::createBoardWithEnemys(unsigned r, unsigned c, unsigned cnt){

    if(viewBoard!= nullptr){
        for (int i=0; i<this->r; i++) {
            delete[] viewBoard[i];
        }
        delete [] viewBoard;
    }
    if(checkBoard!=nullptr){
        for (int i=0; i<this->r; i++) {
            delete[] checkBoard[i];
        }
        delete [] checkBoard;
    }
    this->r = r;
    this->c = c;

    viewBoard = new int*[r];
    checkBoard = new int*[r];
    for (int i=0; i<r; i++) {
        viewBoard[i] = new int[c]{0};
        checkBoard[i] = new int[c]{0};
    }

    unsigned enemyOnField = 0, randR, randC;
    if(enemys!=nullptr){
        for(int i=0; i<cnt_enemy; i++){
            delete enemys[i];
        }
        delete[] enemys;
    }
    this->cnt_enemy = cnt;

    //polimorfic container
    enemys = new CEnemy*[cnt_enemy];

    for(int i=0; i<cnt_enemy; i++){
        switch(rand()%3){
            case 0: enemys[i] = new CEnemy();
                break;
            case 1: {
                enemys[i] = new DeadlyEnemy();
                DeadlyEnemy* de=(DeadlyEnemy*)enemys[i];
                try {
                    de->setPower(i+1);
                }
                catch (const PowerError & e) {
                    std::cerr << typeid( e ).name() << std::endl << e.what() << std::endl;
                    de->setPower( 5 );
                }
            }
            break;
            case 2: enemys[i] = new SuperDeadlyEnemy();
                break;
        }
    }

    unsigned index = 0;
    while(enemyOnField<cnt_enemy){
        //[0, r-1]
        randR = rand()%(r-1-0+1)+0;
        //[0, c-1]
        randC = rand()%c;
        if(viewBoard[randR][randC] == 0){
            if(dynamic_cast<CEnemy*>(enemys[index])!= nullptr){
                viewBoard[randR][randC] = -1;
            }
            if(typeid(DeadlyEnemy*)==typeid(enemys[index])){
                viewBoard[randR][randC] = -2;
            }
            if(dynamic_cast<SuperDeadlyEnemy*>(enemys[index])){
                viewBoard[randR][randC] = -3;
            }
            index++;
            enemyOnField++;
        }
    }
    enemyOnField = 0;

    //fill the board hw
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if(viewBoard[i][j]==-1  || viewBoard[i][j]==-2 || viewBoard[i][j]==-3){
                for(int ii=((i==0)?i:i-1); ii<((i==r-1)?i+1:i+2); ii++){

                    for(int jj=((j==0)?j:(j-1)); jj<((j==c-1)?j+1:j+2); jj++){
                        if(viewBoard[ii][jj]!=-1 && viewBoard[ii][jj]!=-2 && viewBoard[ii][jj]!=-3){
                            viewBoard[ii][jj]++;
                        }
                    }
                }
                enemyOnField++;
            }
            if(enemyOnField==cnt_enemy){
                return 0;
            }
        }
    }
    return 0;
}

int CBoard::operator()(unsigned i, unsigned j) const{
    return viewBoard[i][j];
}



int CBoard::markBoard(unsigned i, unsigned j){
    checkBoard[i][j] = 1;
    return 0;
}

int CBoard::openBoard(unsigned i, unsigned j){
    checkBoard[i][j] = 2;
    return 0;
}

bool CBoard::isEnemy(unsigned i, unsigned j) const{
    return viewBoard[i][j]==-1 || viewBoard[i][j]==-2 || viewBoard[i][j] == -3;
}

unsigned CBoard::setR(unsigned r){
    this->r=r;
    return r;
}
unsigned CBoard::setC(unsigned c){
    this->c=c;
    return c;
}
unsigned CBoard::setCnt_enemy(unsigned cnt){
    cnt_enemy=cnt;
    return cnt;
}

unsigned CBoard::getR() const{
    return r;
}

unsigned CBoard::getC() const{
    return c;
}


std::ostream& CBoard::ins(std::ostream& out) const{
    out << "Print board: \n";
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            out << viewBoard[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}
std::istream& CBoard::ext(std::istream& in){
    int col,row;
    char icon;
    in>>row>>col>>icon;
    setR(row);
    setC(col);
    setCnt_enemy(icon);
    return in;
}
std::ostream& operator<<(std::ostream & out, const CBoard & rhs){
    return rhs.ins(out);
}
std::istream& operator>>(std::istream & in,CBoard & rhs) {
    return rhs.ext(in);
}
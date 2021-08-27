//
// Created by Lachezar on 21.4.2020 г..
//

#include "Game.h"

Game::Game(const CBoard & b, const CPlayer & p, bool m, bool o):
        b(b), p(p), mark(m), open(o){
}

Game::~Game(){
}

int Game::drawBoard() const{
    ///hw to make if the cell in the board is already opened or marked this to be noted to the player
    ///hw you have to consider the checkBoard values in order to draw correct board
    std::cout << std::endl;
    unsigned board_row = b.getR();
    unsigned board_col = b.getC();

    for(int j=0; j<board_col; j++){
        std::cout << " |  ";
    }
    std::cout << std::endl;

    for(int i=0; i<board_row; i++){
        for(int j=0; j<board_col; j++){
            std::cout << "----";
        }
        std::cout << std::endl;
        for(int j=0; j<board_col; j++){
            if(mark){
                if(i==row && j==col) {
                    std::cout << " | !";
                  //  mark;
                }
                else
                    std::cout << " |  " ;
            }
            else{
                if(i==row && j == col){
                    if(b(i, j) == -1 || b(i, j) == -2 || b(i, j) == -3){
                        ///hw to get the proper enemy icon
                        std::cout << getIcon();    //// " |*";
                    }
                    else{
                        std::cout << " | " << b(row, col);
                    }
                }
                else
                    std::cout << " |  " ;
            }
        }
        std::cout << std::endl;
    }
    for(int j=0; j<board_col; j++){
        std::cout << "----";
    }
    std::cout << std::endl;
    for(int j=0; j<board_col; j++){
        std::cout << " |  ";
    }
    std::cout << std::endl;
    return 0;
}

int Game::playGame(){
    ///redraw screen
    system("cls");
    ///draw user info
    std::cout << "Minesweepers Game" << std::endl;
    std::cout << std::endl;
    std::cout << p << std::endl;

    ///draw board
    std::cout << b << std::endl;
    drawBoard();
    std::cout << std::endl;

    ///ask the question to open or mark
    std::cout << "Do you want to open a cell or to mark a cell? (o-open, m-mark): ";
    char answer;
    std::cin >> answer;
    char txt[20];
    if(answer == 'o'){
        open = true;
        mark = false;
        strcpy(txt, "open");
    }
    else{
        open = false;
        mark = true;
        strcpy(txt, "mark");
    }
    std::cout << "On which row you want to " << txt << " a cell? ";
    std::cin >> row;
    std::cout << "On which column you want to " << txt << " a cell? ";
    std::cin >> col;

    ///do the selected action
    if(answer == 'o'){
        b.openBoard(row, col);
    }
    else{
        b.markBoard(row, col);
    }
    ///check if game is over
    ///hw make the according actions in order to check the exact type of the enemy - Enemy, DeadlyEnemy, SuperDeadelyEnemy

    if(answer == 'o' && b.isEnemy(row, col)){
        std::cout << "Game over!!! You selected a mine!!!\n";
        exit(0);
    }
    ///hw calculate the score
    Sleep(100);
    return 0;
}

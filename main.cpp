#include <typeinfo>
#include "Enemy.h"
#include "Player.h"
#include "Board.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <windows.h>

using namespace std;

int main() {

    /*try {
      CPlayer pesho(0, 4, true, "Pesho");
    }
    catch (const out_of_range & exept){

        cerr<< "Out of range is caught here : "<<typeid(exept).name()<< endl <<exept.what()<<endl;
        CPlayer pesho(0, 4, true, "Pesho");
        cout <<pesho<<endl;
    }
    catch (const logic_error & exept){

        cerr<< "Logic error is caught here : "<<typeid(exept).name()<< endl <<exept.what()<<endl;
        CPlayer pesho(0, 4, true, "Pesho");
        cout <<pesho<<endl;
    } catch (...) {
        cerr<<"some exceptions was caught here\n";

    }
*/
    CBoard b;
    b.createBoard(5,5,1);
    cout<<b;

    return 0;
}

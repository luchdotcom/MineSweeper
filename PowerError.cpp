//
// Created by Lachezar on 21.4.2020 г..
//

#include <cstring>
#include "PowerError.h"

PowerError::PowerError( const char *txt, int min, int max ):std::logic_error(txt),min(min),max(max) {

}

const char *PowerError::what() const noexcept {

    char txt[200];
    strcpy(txt,std::logic_error::what());
    strcat(txt,"out of interval [");

    //to be continue
    return txt;
}

//
// Created by Lachezar on 21.4.2020 г..
//

#ifndef MS_21_04_POWERERROR_H
#define MS_21_04_POWERERROR_H

#include <iostream>
#include <stdexcept>

class PowerError : public std::logic_error{
public:
    PowerError( const char*, int,int);
    virtual const char* what()const noexcept ;
private:
    int min,max;

};


#endif //MS_21_04_POWERERROR_H

//
// Created by Daniel on 15/04/2026.
//

#ifndef PROYECTO_1_ERRORVALOR_H
#define PROYECTO_1_ERRORVALOR_H

#include <exception>
using namespace std;

class ErrorValor : public exception
{
    public:
    const char* what() const noexcept override;
};


#endif //PROYECTO_1_ERRORVALOR_H
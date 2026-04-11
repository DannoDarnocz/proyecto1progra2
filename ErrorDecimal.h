//
// Created by axela on 9/4/2026.
//

#ifndef PROYECTO_1_ERRORDECIMAL_H
#define PROYECTO_1_ERRORDECIMAL_H

#include <exception>

using namespace std;

class ErrorDecimal : public exception {
    public:
    const char* what() const noexcept override;
};


#endif //PROYECTO_1_ERRORDECIMAL_H
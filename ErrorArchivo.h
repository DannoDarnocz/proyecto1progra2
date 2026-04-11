//
// Created by axela on 9/4/2026.
//

#ifndef PROYECTO_1_ERRORARCHIVO_H
#define PROYECTO_1_ERRORARCHIVO_H

#include <exception>

using namespace std;

class ErrorArchivo : public exception {
    public:
    const char* what() const noexcept override;
};


#endif //PROYECTO_1_ERRORARCHIVO_H
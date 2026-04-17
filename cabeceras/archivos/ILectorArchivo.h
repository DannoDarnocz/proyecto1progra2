//
// Created by Daniel on 17/04/2026.
//

#ifndef PROYECTO_1_ILECTORARCHIVO_H
#define PROYECTO_1_ILECTORARCHIVO_H
#include <fstream>
using namespace std;
class ILectorArchivo
{
public:
    virtual void leer(ifstream f) = 0;
};


#endif //PROYECTO_1_ILECTORARCHIVO_H
//
// Created by Daniel on 10/04/2026.
//

#ifndef PROYECTO_1_MICROSCOPIO_H
#define PROYECTO_1_MICROSCOPIO_H

#include "Equipo.h"

class Microscopio : public Equipo
{
public:
    Microscopio(double crit, double tiempo);
    string getTipo() const;
};


#endif //PROYECTO_1_MICROSCOPIO_H
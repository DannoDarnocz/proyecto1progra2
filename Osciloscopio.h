//
// Created by Daniel on 10/04/2026.
//

#ifndef PROYECTO_1_OSCILOSCOPIO_H
#define PROYECTO_1_OSCILOSCOPIO_H
#include "Equipo.h"

class Osciloscopio : public Equipo
{
public:
    Osciloscopio(double crit, double tiempo);
    string getTipo() const;
};


#endif //PROYECTO_1_OSCILOSCOPIO_H
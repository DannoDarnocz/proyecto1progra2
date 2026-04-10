//
// Created by axel on 9/4/2026.
//

#ifndef PROYECTO_1_COMPUTADORAESCRITORIO_H
#define PROYECTO_1_COMPUTADORAESCRITORIO_H
#include "Equipo.h"


class ComputadoraEscritorio : public Equipo {
public:
    ComputadoraEscritorio(double crit, double tiempo);
    string getTipo() const;
};


#endif //PROYECTO_1_COMPUTADORAESCRITORIO_H
//
// Created by axel on 9/4/2026.
//

#ifndef PROYECTO_1_LAPTOP_H
#define PROYECTO_1_LAPTOP_H
#include "Equipo.h"


class Laptop : public Equipo {
public:
    Laptop();
    Laptop(double crit, double tiempo);
    string getTipo() const;
};


#endif //PROYECTO_1_LAPTOP_H
//
// Created by axela on 9/4/2026.
//

#ifndef PROYECTO_1_INCIDENCIA_H
#define PROYECTO_1_INCIDENCIA_H
#include "Equipo.h"

class Equipo;

class Incidencia {
private:
    Equipo* equipo;
    int severidad;
    int dia;
public:
    Incidencia(Equipo* e, int severidad, int dia);
};


#endif //PROYECTO_1_INCIDENCIA_H
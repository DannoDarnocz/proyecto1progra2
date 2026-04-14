//
// Created by axela on 9/4/2026.
//

#ifndef PROYECTO_1_INCIDENCIA_H
#define PROYECTO_1_INCIDENCIA_H
#include "Equipo.h"

class Equipo;

class Incidencia {
private:
    Equipo* equipo; //Equipo que presenta esta incidencia
    int severidad; //0-2 Severidad
    int dia; //Dia en el que se presento la incidencia
public:
    Incidencia(Equipo* e, int severidad, int dia);
    int getSeveridad() const;
};


#endif //PROYECTO_1_INCIDENCIA_H
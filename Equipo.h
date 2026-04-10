//
// Created by Daniel on 08/04/2026.
//

#ifndef PROYECTO_1_EQUIPO_H
#define PROYECTO_1_EQUIPO_H
#include <iostream>
#include "ListaIncidencia.h"
using namespace std;

class Equipo {
protected:
    string id;
    double criticidad;
    double tiempoInactividad;
    ListaIncidencia* incidencias;
public:
    Equipo(double crit, double tiempo);
    string getId() const;
    double getPrioridad() const;
    int cantidadIncidencias(); //Devuelve cantidad de incidencias existentes
    double calcPrioridad();    //Calcula su nivel de prioridad
    void aplicarDegradacion(int dia); //Aplica degradación al equipo en un dia especifico
    virtual string getTipo() const = 0; //Devuelve tipo de las hijas
};


#endif //PROYECTO_1_EQUIPO_H
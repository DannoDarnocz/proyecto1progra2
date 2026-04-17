//
// Created by Daniel on 08/04/2026.
//

#ifndef PROYECTO_1_EQUIPO_H
#define PROYECTO_1_EQUIPO_H
#include <iostream>
#include <string>
#include <sstream>
#include "../listas/ListaIncidencia.h"
#include "../Incidencia.h"
using namespace std;

class ListaIncidencia;
class Incidencia;

class Equipo {
protected:
    static int contador; //cuenta cuantos equipos se han creado
    string id;
    int diaMantenimiento; // día en el cual se le hizo el último mantenimiento
    float criticidad;
    ListaIncidencia* incidencias;
public:
    Equipo(double crit, int diaMant);
    //Gets
    string getId() const;
    int getDiaMant() const;
    float getCriticidad() const;
    Incidencia* obtenerIncidencia(int pos) const;
    ListaIncidencia* obtenerListaIncidencia() const;
    void eliminarIncidencias();
    //Sets
    void setCriticidad(float criticidad);
    //Generales
    int tiempoInactivo(int diaActual) const; //Devuelve cantidad de tiempo sin mantenimiento
    int cantidadIncidencias() const; //Devuelve cantidad de incidencias existentes
    double calcPrioridad(int) const;    //Calcula su nivel de prioridad
    void aplicarDegradacion(int dia); //Aplica degradación al equipo en un dia especifico
    virtual string getTipo() const = 0; //Devuelve tipo de las hijas
    virtual string toString() const; //Devuelve todos los atributos
};


#endif //PROYECTO_1_EQUIPO_H


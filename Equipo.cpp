//
// Created by Daniel on 08/04/2026.
//

#include "Equipo.h"
#include "ctime"

int Equipo::contador = 0;

Equipo::Equipo(double crit, int diaMant) {
    contador++;
    this->id=to_string(contador);
    this->criticidad=crit;
    this->diaMantenimiento=diaMant;
    this->incidencias = new ListaIncidencia(); //Lista personalizada para incidencias
}

string Equipo::getId() const { return this->id; }

int Equipo::cantidadIncidencias() const {
    return incidencias->getTam(); //Metodo retorna variable int tamaño
}

double Equipo::calcPrioridad(int diaActual) const {
    return (criticidad*0.5)+((double)cantidadIncidencias()*0.3)+((diaActual-diaMantenimiento)*0.2);
}

void Equipo::aplicarDegradacion(int dia) {
    srand(time(NULL)); // generar nueva semilla
    double valor1 = (rand() % 100) + 1; //Rango 1-100 Crit
    double valor2 = (rand() % 100) + 1; //Rango 1-100 Tiempo
    int valor3 = (rand() % 2); //Rango 0-2 Severidad Incidencia
    incidencias->insertarInicio(this, valor3, dia);
}

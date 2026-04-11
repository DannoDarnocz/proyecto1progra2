//
// Created by Daniel on 08/04/2026.
//

#include "Equipo.h"
#include "ctime"

int Equipo::contador = 0;

Equipo::Equipo(double crit, double tiempo) {
    contador++;
    this->id=to_string(contador);
    this->incidencias = new ListaIncidencia(); //Lista personalizada para incidencias
}

string Equipo::getId() const { return this->id; }

int Equipo::cantidadIncidencias() {
    return incidencias->getTam(); //Metodo retorna variable int tamaño
}

double Equipo::calcPrioridad() const {
    return (criticidad*0.5)+(cantidadIncidencias()*0.3)+(tiempoInactividad*0.2);
}

void Equipo::aplicarDegradacion(int dia) {
    srand(time(NULL)); // generar nueva semilla
    double valor1 = (rand() % 100) + 1; //Rango 1-100 Crit
    double valor2 = (rand() % 100) + 1; //Rango 1-100 Tiempo
    int valor3 = (rand() % 2); //Rango 0-2 Severidad Incidencia
    incidencias->insertarInicio(this, valor3, dia);
}

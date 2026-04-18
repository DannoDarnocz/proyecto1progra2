//
// Created by Daniel on 08/04/2026.
//

#include "../../cabeceras/equipos/Equipo.h"
#include "../../cabeceras/excepciones/ErrorRango.h"
#include "ctime"

int Equipo::contador = 0;

Equipo::Equipo(double crit, int diaMant) {
    this->incidencias = new ListaIncidencia(); //Lista personalizada para incidencias
    this->id=to_string(contador);
    this->criticidad=crit;
    if (diaMant>=0 && diaMant<=30)
    {
        this->diaMantenimiento=diaMant;
    }
    else
    {
        throw ErrorRango("El dia de mantenimiento debe estar entre 0 y 30");
    }
    contador++;
}

string Equipo::getId() const { return this->id; }
int Equipo::getDiaMant() const { return this->diaMantenimiento; }
float Equipo::getCriticidad() const { return this->criticidad; }

Incidencia* Equipo::obtenerIncidencia(int pos) const {
    NodoIncidencia* i = incidencias->buscarPorPos(pos);
    if (!i) { return nullptr;}
    return i->getIncidencia();
}
ListaIncidencia* Equipo::obtenerListaIncidencia() const { return incidencias; }

void Equipo::eliminarIncidencias()
{
    // solo Equipo conoce incidencias, se puede borrar y crear una nueva, y listo
    if (incidencias) delete incidencias;
    incidencias = new ListaIncidencia();
}

void Equipo::setCriticidad(float criticidad) {
    this->criticidad=criticidad;
}

int Equipo::cantidadIncidencias() const {
    return incidencias->getTam(); //Metodo retorna variable int tamano
}

void Equipo::generarId() {
    id = getPrefix() + "-" + id;
}

int Equipo::tiempoInactivo(int diaActual) const { return (diaActual-diaMantenimiento); }

double Equipo::calcPrioridad(int diaActual) const {
    return (criticidad*0.5)+((double)cantidadIncidencias()*0.3)+(tiempoInactivo(diaActual)*0.2);
}

void Equipo::aplicarDegradacion(int dia) {
    srand(time(NULL)); // generar nueva semilla
    double valor1 = (rand() % 100) + 1; //Rango 1-100 Crit
    int valor3 = (rand() % 2); //Rango 0-2 Severidad Incidencia
    criticidad+valor1 > 100 ? criticidad=100 : criticidad+=valor1;
    if (criticidad > 0) { incidencias->insertarInicio(this, valor3, dia); }
}

string Equipo::toString() const {
    stringstream s;
    s << "ID: " << id << " | Tipo: " << getTipo() << " | Criticidad: " << criticidad
      << " | Dia Mantenimiento: " << diaMantenimiento << " | Incidencias: " << cantidadIncidencias();
    return s.str();
}


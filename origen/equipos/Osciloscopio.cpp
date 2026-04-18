//
// Created by Daniel on 10/04/2026.
//

#include "../../cabeceras/equipos/Osciloscopio.h"

Osciloscopio::Osciloscopio() : Equipo(0,0) {}
Osciloscopio::Osciloscopio(double crit, double tiempo) : Equipo(crit, tiempo) {}

string Osciloscopio::getTipo() const { return "Osciloscopio";}

string Osciloscopio::getPrefix() const { return "OSC"; }
void Osciloscopio::leerDatos(stringstream &ss) {
    getline(ss,id,',');
    ss >> criticidad; ss.ignore();
    ss >> diaMantenimiento; ss.ignore();
}

Equipo *Osciloscopio::crear() {
    return new Osciloscopio();
}

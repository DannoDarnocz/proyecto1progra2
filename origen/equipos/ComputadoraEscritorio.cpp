//
// Created by axel on 9/4/2026.
//

#include "../../cabeceras/equipos/ComputadoraEscritorio.h"

ComputadoraEscritorio::ComputadoraEscritorio() : Equipo(0,0) {}
ComputadoraEscritorio::ComputadoraEscritorio(double crit, double tiempo) : Equipo(crit, tiempo) {}

string ComputadoraEscritorio::getTipo() const { return "Computadora de escritorio"; }

string ComputadoraEscritorio::getPrefix() const { return "PC"; }
void ComputadoraEscritorio::leerDatos(stringstream &ss) {
    getline(ss,id,',');
    ss >> criticidad; ss.ignore();
    ss >> diaMantenimiento; ss.ignore();
}

Equipo *ComputadoraEscritorio::crear() {
    return new ComputadoraEscritorio();
}

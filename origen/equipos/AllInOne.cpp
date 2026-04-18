//
// Created by axel on 9/4/2026.
//

#include "../../cabeceras/equipos/AllInOne.h"

AllInOne::AllInOne() : Equipo(0,0) {}
AllInOne::AllInOne(double crit, double tiempo) : Equipo(crit, tiempo) {}

string AllInOne::getTipo() const { return "All-In-One"; }

string AllInOne::getPrefix() const { return "AIO"; }
void AllInOne::leerDatos(stringstream &ss) {
    getline(ss,id,',');
    ss >> criticidad; ss.ignore();
    ss >> diaMantenimiento; ss.ignore();
}

Equipo *AllInOne::crear() {
    return new AllInOne();
}

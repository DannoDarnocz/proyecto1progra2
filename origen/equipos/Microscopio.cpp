//
// Created by Daniel on 10/04/2026.
//

#include "../../cabeceras/equipos/Microscopio.h"

Microscopio::Microscopio() : Equipo(0,0) {}
Microscopio::Microscopio(double crit, double tiempo) : Equipo(crit, tiempo) {}

string Microscopio::getTipo() const { return "Microscopio"; }

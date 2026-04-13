//
// Created by Daniel on 10/04/2026.
//

#include "Microscopio.h"

Microscopio::Microscopio(double crit, double tiempo) : Equipo(crit, tiempo) {}

string Microscopio::getTipo() const { return "Microscopio"; }

//
// Created by Daniel on 10/04/2026.
//

#include "../../cabeceras/equipos/Osciloscopio.h"

Osciloscopio::Osciloscopio() : Equipo(0,0) {}
Osciloscopio::Osciloscopio(double crit, double tiempo) : Equipo(crit, tiempo) {}

string Osciloscopio::getTipo() const { return "Osciloscopio";}
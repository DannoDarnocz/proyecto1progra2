//
// Created by axel on 9/4/2026.
//

#include "../../cabeceras/equipos/Laptop.h"

Laptop::Laptop() : Equipo(0,0) { }
Laptop::Laptop(double crit, double tiempo) : Equipo(crit, tiempo) { }

string Laptop::getTipo() const { return "Laptop"; }
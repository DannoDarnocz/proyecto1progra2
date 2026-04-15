//
// Created by axel on 9/4/2026.
//

#include "AllInOne.h"

AllInOne::AllInOne() : Equipo(0,0) {}
AllInOne::AllInOne(double crit, double tiempo) : Equipo(crit, tiempo) {}

string AllInOne::getTipo() const { return "All-In-One"; }

//
// Created by axel on 9/4/2026.
//

#include "ComputadoraEscritorio.h"

ComputadoraEscritorio::ComputadoraEscritorio(double crit, double tiempo) : Equipo(crit, tiempo) {}

string ComputadoraEscritorio::getTipo() const { return "Computadora de escritorio"; }

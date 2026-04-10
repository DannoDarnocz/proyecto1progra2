//
// Created by axel on 9/4/2026.
//

#include "NodoEquipo.h"

NodoEquipo::NodoEquipo() : miEquipo(nullptr), sig(nullptr) {}
Equipo* NodoEquipo::getEquipo() const { return miEquipo; }
void NodoEquipo::setEquipo(Equipo* O) { miEquipo = O; }
NodoEquipo* NodoEquipo::getSig() const { return sig; }
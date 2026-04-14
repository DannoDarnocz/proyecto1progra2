//
// Created by axela on 9/4/2026.
//

#include "Incidencia.h"

Incidencia::Incidencia(Equipo* e, int severidad, int dia):equipo(e),severidad(severidad),dia(dia){};

int Incidencia::getSeveridad() const { return severidad; }

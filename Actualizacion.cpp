//
// Created by axela on 9/4/2026.
//

#include "Actualizacion.h"

Actualizacion::Actualizacion(Mantenimiento *m) : MantenimientoDecorador(m) {}

string Actualizacion::descripcion() const { return mant->descripcion() + "Actualizacion Software"; }

void Actualizacion::arreglar(Equipo *e) {
    int contador=0;
    for (int i=0;i<e->cantidadIncidencias();i++) {
        Incidencia* inci = e->obtenerIncidencia(i);
        if (!inci) { continue; }
        if (inci->getSeveridad() == 2) { e->obtenerListaIncidencia()->eliminarPos(i); }
        contador++;
        if (contador > 10) {break;}
    }
    e->setCriticidad(e->getCriticidad()-15);
    mant->arreglar(e);
}

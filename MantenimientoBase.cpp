//
// Created by axela on 9/4/2026.
//

#include "MantenimientoBase.h"

string MantenimientoBase::descripcion() const {
    return "Mantenimiento basico";
}
void MantenimientoBase::arreglar(Equipo* e) {
    if (e->cantidadIncidencias()==0) {return;}
    if (e->cantidadIncidencias()==1) { e->obtenerListaIncidencia()->eliminarInicio(); }
    int contador=0;
    for (int i=0;i<e->cantidadIncidencias();i++) {
        Incidencia* inci = e->obtenerIncidencia(i);
        if (!inci) { continue; }
        if (inci->getSeveridad() == 2) { e->obtenerListaIncidencia()->eliminarPos(i); }
        contador++;
        if (contador > 5) {break;}
    }
    e->setCriticidad(e->getCriticidad()-50);
}
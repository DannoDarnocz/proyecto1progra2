//
// Created by Daniel on 15/04/2026.
//

#include "../../cabeceras/mantenimientos/MantenimientoSoftware.h"

#include "../../cabeceras/mantenimientos/MantenimientoDecorador.h"


string MantenimientoSoftware::descripcion() const
{
   return mant->descripcion() + " + Mantenimiento de software";
};
void MantenimientoSoftware::arreglar(Equipo *e)
{
   mant->arreglar(e);
   e->setCriticidad(e->getCriticidad()-20); // puede quedar negativo sin problema
};
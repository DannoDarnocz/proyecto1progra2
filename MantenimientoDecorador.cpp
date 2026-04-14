//
// Created by axela on 9/4/2026.
//

#include "MantenimientoDecorador.h"

MantenimientoDecorador::MantenimientoDecorador(Mantenimiento *m) {
    this->mant=m;
}

MantenimientoDecorador::~MantenimientoDecorador() {
    delete mant;
}

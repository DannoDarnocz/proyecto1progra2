//
// Created by axela on 9/4/2026.
//

#ifndef PROYECTO_1_ACTUALIZACION_H
#define PROYECTO_1_ACTUALIZACION_H
#include "MantenimientoDecorador.h"


class Actualizacion : public MantenimientoDecorador {
public:
    Actualizacion(Mantenimiento* m);
    string descripcion() const override;
    void arreglar(Equipo *e) override;
};


#endif //PROYECTO_1_ACTUALIZACION_H
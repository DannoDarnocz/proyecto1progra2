//
// Created by axel on 9/4/2026.
//

#ifndef PROYECTO_1_ALLINONE_H
#define PROYECTO_1_ALLINONE_H
#include "Equipo.h"


class AllInOne : public Equipo {
public:
    AllInOne();
    AllInOne(double crit, double tiempo);
    string getTipo() const;
};


#endif //PROYECTO_1_ALLINONE_H
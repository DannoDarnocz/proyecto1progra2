//
// Created by axela on 9/4/2026.
//

#include "ErrorArchivo.h"

const char* ErrorArchivo::what() const noexcept
{
    return "Ha ocurrido un error durante la manipulacion del archivo.";
}

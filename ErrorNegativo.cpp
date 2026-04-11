//
// Created by axela on 9/4/2026.
//

#include "ErrorNegativo.h"

const char* ErrorNegativo::what() const noexcept
{
    return "El valor no puede ser negativo.";
}
//
// Created by Daniel on 15/04/2026.
//

#include "ErrorValor.h"

const char* ErrorValor::what() const noexcept
{
    return "El valor ingresado es invalido.";
}
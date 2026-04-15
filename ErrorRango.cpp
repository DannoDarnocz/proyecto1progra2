//
// Created by Daniel on 15/04/2026.
//
//
#include "ErrorRango.h"

const char* ErrorRango::what() const noexcept
{
    return "El valor esta fuera del rango permitido.";
}
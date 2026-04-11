//
// Created by axela on 9/4/2026.
//

#include "ErrorCast.h"

const char* ErrorCast::what() const noexcept
{
    return "El casteo no se pudo hacer de forma correcta.";
}

//
// Created by axela on 9/4/2026.
//

#include "ErrorDecimal.h"

const char* ErrorDecimal::what() const noexcept
{
    return "El valor no puede ser decimal.";
}

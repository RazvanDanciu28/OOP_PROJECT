#include "excpetions.h"

InvalidAge::InvalidAge() = default;
const char *InvalidAge::what() const noexcept {
    return "Varsta invalida";
}

InvalidWeight::InvalidWeight() = default;
const char *InvalidWeight::what() const noexcept {
    return "Greutate invalida";
}

ambele::ambele() = default;
const char *ambele::what() const noexcept {
    return "Varsta si greutate invalide!";
}
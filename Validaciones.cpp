#include <iostream>
#include "Validaciones.h"
using namespace std;


bool esPalabraValida(const char* palabra) {
    for (int i = 0; palabra[i] != '\0'; ++i) {
        // Si no es letra Y no es espacio, es inválido
        if (!isalpha(static_cast<unsigned char>(palabra[i])) && !isspace(static_cast<unsigned char>(palabra[i]))) {
            return false;
        }
    }
    return true;
}


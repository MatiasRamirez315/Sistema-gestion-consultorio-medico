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

bool esEnteroValido(const string& input) {
    for(char c : input) {
        if(!isdigit(c)) {
            return false;
        }
    }
    return !input.empty();
}

int obtenerEnteroValidado(const string& mensaje) {
    string input;

    cout << mensaje;
    cin >> input;

    while(!esEnteroValido(input) || stoi(input) <= 0) {
        cout << "Ingrese un numero entero mayor a 0: ";
        cin >> input;
    }

    return stoi(input);
}

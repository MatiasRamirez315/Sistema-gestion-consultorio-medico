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

 bool esBooleanoValido(const string& input) {
    return input == "0" || input == "1";
}

bool obtenerBooleanoValidado(const string& mensaje) {
    string input;

    cout << mensaje;
    cin >> input;

    while (!esBooleanoValido(input)) {
        cout << "Error. Ingrese 0 o 1: ";
        cin >> input;
    }

    return input == "1";
}

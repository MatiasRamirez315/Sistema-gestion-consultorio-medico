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

    while(!esEnteroValido(input) || stoi(input) < 0) {
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

bool esEnteroPositivoValido(const string& input) {
    if (input.empty()) {
        return false;
    }

    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return stoi(input) > 0;
}

int obtenerEnteroPositivo(const string& mensaje) {
    string input;

    cout << mensaje;
    cin >> input;

    while (!esEnteroPositivoValido(input)) {
        cout << "Error. Ingrese un numero entero positivo: ";
        cin >> input;
    }

    return stoi(input);
}

bool  FechaMenorIgualActual (Fecha fecha){
    Fecha hoy;
    hoy.setCurrentDate();

    if (fecha.getAnio() > hoy.getAnio()){
        return false;
    }

    if(fecha.getMes() > hoy.getMes()){
        return false;
    }

    if(fecha.getDia() > hoy.getDia()){
        return false;
    }

    return true;

}

#include <iostream>
#include "Validaciones.h"
#include "Fecha.h"
using namespace std;


bool esPalabraValida(const char* palabra) {
    for (int i = 0; palabra[i] != '\0'; ++i) {
        // Si no es letra Y no es espacio, es inv�lido
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

int obtenerHoraValidada() {
    string input;
    cin >> input;

    while(!esEnteroValido(input) || (stoi(input) < 8 || stoi(input) > 16)) {
        cout << "Ingrese un horario valido..." << endl;
        cout << "Ingrese la hora (08 a 16): " << endl;
        cin >> input;
    }

    return stoi(input);
}

int obtenerMinutosValidados() {
    string input;
    cin >> input;

    while(!esEnteroValido(input) || ((stoi(input) != 00 || stoi(input) != 0) && stoi(input) != 30)) {
        cout << "Ingrese un horario valido..." << endl;
        cout << "Ingrese los minutos (00/30)" << endl;
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

bool FechaMenorIgualActual (Fecha fecha){
    Fecha hoy;
    hoy.setCurrentDate();

    if (hoy >= fecha) {
        return true;
    }
    return false;
}

bool FechaMayorIgualActual (Fecha fecha){
    Fecha hoy;
    hoy.setCurrentDate();

    if(fecha >= hoy){
        return true;
    }

    return false;
}

bool esFloatValido(const string& input) {
    if (input.empty()) {
        return false;
    }

    bool tienePunto = false;

    for (char c : input) {
        if (c == '.') {
            if (tienePunto) {
                return false; // Ya había un punto
            }
            tienePunto = true;
        }
        else if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

float obtenerFloatValidado(const string& mensaje) {
    string input;

    cout << mensaje;
    cin >> input;

    while (!esFloatValido(input) || stof(input) < 0) {
        cout << "Ingrese un numero decimal mayor o igual a 0: ";
        cin >> input;
    }

    return stof(input);
}

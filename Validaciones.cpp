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
  for (char c : input) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

int obtenerEnteroValidado(const string& mensaje) {
  string input;
  cout << mensaje;
  cin >> input;
  cin.ignore();

  while (!esEnteroValido(input)) {
    cout << "Ingrese en formato numerico. Por favor, intentelo nuevamente: ";
    cin >> input;
    cin.ignore();
  }

  return stoi(input);
}

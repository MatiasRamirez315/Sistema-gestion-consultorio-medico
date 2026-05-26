//Alumno: Matias Hernan Ramirez
#include "Persona.h"
#include <cstring>

void Persona::setNombre (const char *nombre){
strcpy(_nombre,nombre);
};
void Persona::setApellido(const char *apellido){
strcpy(_apellido, apellido);
};
void Persona::setDNI(int dni){
_dni = dni;
};

const char* Persona::getNombre(){
    return _nombre;
    };
const char* Persona::getApellido(){
    return _apellido;
    };
int Persona::getDNI(){
    return _dni;
    };



void Persona::Cargar(){
    cout << "ingrese el nombre : ";
    cin>> _nombre;
    cout << "ingrese el apellido: ";
    cin >> _apellido;
    cout << "ingrese su dni: ";
    cin >> _dni;

};
void Persona::Mostrar(){
    cout << "Nombre: " << _nombre;
    cout << "Apellido: " << _apellido;
    cout << "DNI: " << _dni;
};

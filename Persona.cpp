#include "Persona.h"
#include <cstring>

void Persona::setNombre (const char *nombre){
    strcpy(_nombre,nombre);
}

void Persona::setApellido(const char *apellido){
    strcpy(_apellido, apellido);
}

void Persona::setDNI(int dni){
    _dni = dni;
}

const char* Persona::getNombre(){
    return _nombre;
}

const char* Persona::getApellido(){
    return _apellido;
}

int Persona::getDNI(){
    return _dni;
}

void Persona::Cargar(){

    cout << "Ingrese el nombre : ";

    cin.getline (_nombre,30);
    cout << "Ingrese el apellido: ";

    cin.getline (_apellido,30);
    //cin >> _apellido;
    cout << "Ingrese el DNI: ";

    cin >> _dni;
}

void Persona::Mostrar(){
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _dni << endl;
}

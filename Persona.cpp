#include "Persona.h"
#include <cstring>

using namespace std;

void Persona::setNombre (string nombre){
_nombre = nombre;

}

void Persona::setApellido(string apellido){
_apellido, apellido;

}

void Persona::setDNI(int dni){
    _dni = dni;
}

string  Persona::getNombre(){
    return _nombre;
}

string Persona::getApellido(){
    return _apellido;
}

int Persona::getDNI(){
    return _dni;
}

void Persona::Cargar(){

    cout << "Ingrese el nombre : ";

    cin >>_nombre;
    cout << "Ingrese el apellido: ";

    cin>> _apellido;
    //cin >> _apellido;
    cout << "Ingrese el DNI: ";

    cin >> _dni;
}

void Persona::Mostrar(){
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _dni << endl;
}

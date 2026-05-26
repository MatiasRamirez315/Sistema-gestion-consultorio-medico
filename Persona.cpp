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
void Persona::setFechaNacimiento(Fecha fechaNac){
_fechaNacimiento = fechaNac;
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

Fecha Persona::getFechaNac(){
    return _fechaNacimiento;
    };

void Persona::Cargar(){
    cout << "ingrese el nombre : ";
    cin>> _nombre;
    cout << "ingrese el apellido: ";
    cin >> _apellido;
    cout << "ingrese su dni: ";
    cin >> _dni;
    _fechaNacimiento.CargarFecha();

};
void Persona::Mostrar(){
    cout << "Nombre: " << _nombre;
    cout << "Apellido: " << _apellido;
    cout << "DNI: " << _dni;
    _fechaNacimiento.toString();
};

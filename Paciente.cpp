#include "Paciente.h"
#include "Persona.h"
#include "Fecha.h"
#include <cstring>

void Paciente::setIdPaciente(int ID){
    _idPaciente = ID;
}

void Paciente::setTelefono(const char* tel){
    strcpy(_telefono,tel);
}

void Paciente::setEmail(const char* mail){
    strcpy(_email,mail);
}

void Paciente::setGenero(char g){
    _genero = g;
}

void Paciente::setIdObraSocial(int id){
    _idObraSocial = id;
}

void Paciente::setFechaNacimiento(Fecha fechaNac){
    _fechaNacimiento = fechaNac;
}

void Paciente::setEstado(bool estado){
    _estado = estado;
}

int Paciente::getIdPaciente(){
    return _idPaciente;
}

const char* Paciente::getTelefono(){
    return _telefono;
}

const char* Paciente::getEmail(){
    return _email;
}

char Paciente::getGenero(){
    return _genero;
}

int Paciente::getIdObraSocial(){
    return _idObraSocial;
}

Fecha Paciente::getFechaNac(){
    return _fechaNacimiento;
}

bool Paciente::getEstado(){
    return _estado;
}

void Paciente::CargarPaciente(){
    Persona p;
    p.Cargar();
    cout << "Ingrese el ID del paciente: ";
    cin >> _idPaciente;
    cout << "Ingrese el telefono: ";
    cin.ignore();
    cin.getline(_telefono,20);
    cout << "Ingrese el email: ";
    cin.ignore();
    cin.getline(_email,30);
    cout << "Ingrese el genero (F o M): ";
    cin >> _genero;
    cout << "Ingrese el ID de la obra social: ";
    cin >> _idObraSocial;
    _fechaNacimiento.CargarFecha();
    setEstado(true);
}

void Paciente::MostrarPaciente(){
    Persona p;
    p.Mostrar();
    cout << "ID del paciente :"  << _idPaciente << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Genero: " << _genero;
    cout << "ID de la obra social: " << _idObraSocial;
    cout << "Fecha de nacimiento: " << _fechaNacimiento.toString();
    cout << "Estado: " << _estado;
}

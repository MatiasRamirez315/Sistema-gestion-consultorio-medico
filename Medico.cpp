#include "Medico.h"
#include "Persona.h"
#include "Fecha.h"
#include <cstring>

void Medico::setIdMedico(int id){
    _idMedico = id;
}

void Medico::setIdPuesto(int id){
    _idPuesto = id;
}

void Medico::setIdEspecialidad(int id){
    _idEspecialidad = id;
}

void Medico::setMatriculaProfesional(const char* mat){
    strcpy(_matriculaProfesional,mat);
}

void Medico::setFechaIngreso(Fecha f){
    _fechaIngreso.setAnio(f.getAnio());
    _fechaIngreso.setMes(f.getMes());
    _fechaIngreso.setDia(f.getDia());
}

void Medico::setEstado(bool e){
    _estado = e;
}

int Medico::getIdMedico(){
    return _idMedico;
}

int Medico::getIdPuesto(){
    return _idPuesto;
}

int Medico::getIdEspecialidad() {
    return _idEspecialidad;
}

const char* Medico::getMatriculaProfesional(){
    return _matriculaProfesional;
}

Fecha Medico::getFechaIngreso() {
    return _fechaIngreso;
}

bool Medico::getEstado() {
    return _estado;
}

void Medico::Cargar(){
    Persona p;
    p.Cargar();
    cout << "Ingrese el ID del medico: ";
    cin >> _idMedico;
    cout << "Ingrese el ID del puesto: ";
    cin >> _idPuesto;
    //agregar opciones de tipos de puesto ej: 1---- odontologo.
    cout << "Ingrese el ID de la especialidad: ";
    cin >> _idEspecialidad;
     //agregar opciones de tipos de puesto ej: 1---- odontologo     redundante ????????.
    cout << "Ingrese la matricula: ";
    cin.ignore();
    cin.getline(_matriculaProfesional,12);
    _fechaIngreso.CargarFecha();
    setEstado(true);
}

void Medico::Mostrar(){
    Persona p;
    p.Mostrar();
    cout << "ID del medico :"  << _idMedico << endl;
    cout << "ID del puesto: " << _idPuesto << endl;
    cout << "ID de la especialidad: " << _idEspecialidad << endl;
    cout << "Matricula: " << _matriculaProfesional;
    cout << "Fecha de ingreso: " << _fechaIngreso.toString();
    cout << "Estado: " << _estado;
}

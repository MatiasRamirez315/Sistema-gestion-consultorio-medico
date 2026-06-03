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

    cout << "Ingrese el ID del medico: " << endl;
    cin >> _idMedico;

    cout << "Ingrese el ID del puesto: ";
    cin >> _idPuesto;
    //agregar opciones de tipos de puesto ej: 1---- odontologo.
    cout << "Ingrese el ID de la especialidad: " << endl;

    cout << "1- Clinico" <<endl;
    cout << "2- Oftalmologo" << endl;
    cout << "3- Odontologo" << endl;
    cout << "4- Pediatra" << endl;
    cout << "5- Traumatologo " << endl;
    cout << "6- Dermatologo" << endl;
    cout << "7- Cardiologo" << endl;
    do{
    cin >> _idEspecialidad;
        if (_idEspecialidad < 1 || _idEspecialidad  > 7){
            cout << "Error al elegir la especialidad, vuelva a seleccionar." << endl;
        }
    }while (_idEspecialidad < 1 || _idEspecialidad  > 7 );

    cout << "Ingrese la matricula: ";
    cin >> _matriculaProfesional;
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

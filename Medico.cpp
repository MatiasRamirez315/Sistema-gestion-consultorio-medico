//Alumno: Matias Hernan Ramirez
#include "Medico.h"
#include "Persona.h"
#include "Fecha.h"
#include <cstring>
void Medico::setIdMedico(int id){
_idMedico = id;
};

void Medico::setIdPuesto(int id){
_idPuesto = id;
};

void Medico::setIdEspecialidad(int id){
_idEspecialidad = id;
};

void Medico::setMatriculaProfesional(const char* mat){
strcpy(_matriculaProfesional,mat);
};

void Medico::setFechaIngreso(Fecha f){
_fechaIngreso.setAnio(f.getAnio());
_fechaIngreso.setMes(f.getMes());
_fechaIngreso.setDia(f.getDia());
};

void Medico::setEstado(bool e){
_estado = e;
};

int Medico::getIdMedico(){
    return _idMedico;
};

int Medico::getIdPuesto(){
    return _idPuesto;
};

int Medico::getIdEspecialidad() {
    return _idEspecialidad;
};

const char* Medico::getMatriculaProfesional(){
    return _matriculaProfesional;
};

Fecha Medico::getFechaIngreso() {
    return _fechaIngreso;
};

bool Medico::getEstado() {
    return _estado;
};

void Medico::Cargar(){
Persona p;
p.Cargar();

cout << "ingrese el ID del medico: ";
cin >> _idMedico;
cout << "ingrese su puesto: ";
cin >> _idPuesto;
cout << "ingrese el id de especialidad: ";
cin>> _idEspecialidad;
cin.ignore();

cout << "ingrese la matricula: ";
cin.getline(_matriculaProfesional,12);

cout << "ingrese cuando ingreso: ";
_fechaIngreso.CargarFecha();
setEstado(true);

};
void Medico::Mostrar(){
    Persona p;
    cout << "Nombre: " << p.getNombre();
    cout << "Apellido: " << p.getApellido();
    cout << "DNI: " << p.getDNI();
   // cout << "Fecha de nacimiento: " << p.getFechaNac().toString();
    cout << "ID del medico :"  << _idMedico << endl;
    cout << "ID del puesto: " << _idPuesto << endl;
    cout << "ID de la especialidad: " << _idEspecialidad << endl;
    cout << "Matricula: " << _matriculaProfesional;
    cout << "Fecha de ingreso: " << _fechaIngreso.toString();
    cout << "estado: " << _estado;
}

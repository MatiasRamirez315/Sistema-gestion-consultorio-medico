//Alumno: Matias Hernan Ramirez
#include "Paciente.h"
#include <cstring>

void Paciente::setIdPaciente(int ID){
_idPaciente = ID;
};

void Paciente::setTelefono(const char* tel){
strcpy(_telefono,tel);
};
void Paciente::setEmail(const char* mail){
strcpy(_email,mail);
};

void Paciente::setGenero(char g){
_genero = g;
};

void Paciente::setIdObraSocial(int id){
_idObraSocial = id;
};

void Paciente::setEstado(bool estado){
_estado = estado;
};

int Paciente::getIdPaciente(){
return _idPaciente;
};

const char* Paciente::getTelefono(){
return _telefono;
};

const char* Paciente::getEmail(){
return _email;
};

char  Paciente::getGenero(){
return _genero;
};

int  Paciente::getIdObraSocial(){
return _idObraSocial;
};

bool  Paciente::getEstado(){
return _estado;
};

void  Paciente::CargarPaciente(){
Persona p;

p.Cargar();
};

void  Paciente::MostrarPaciente(){
Persona p;

p.Mostrar();

};

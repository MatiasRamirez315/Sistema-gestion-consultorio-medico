#include <iostream>
#include "Turnos.h"
#include <cstring>

using namespace std;

void Turnos::setIdTurno(int id){
_idTurno = id;
}

void Turnos::setIdAgendaMedico(int idAgenda){
_idAgendaMedicos= idAgenda;
}

void Turnos::setIdPaciente(int idPaciente){
_idPaciente = idPaciente;
}

void Turnos::setMotivo(const char* motivo)
{
    strcpy(_motivo, motivo);

}

void Turnos::setEstado(bool estado){
_estado = estado;
}

// GETTERS
int Turnos::getIdTurno(){
return _idTurno;
}

int Turnos::getIdAgendaMedico(){
return _idAgendaMedicos;
}

int Turnos::getIdPaciente(){
return _idPaciente;
}

const char* Turnos::getMotivo() {
return _motivo;
}

bool Turnos::getEstado(){
return _estado;
}


void Turnos::Cargar(){
    cout << "Ingrese el ID del turno: ";
    cin >> _idTurno;

    cout << "Ingrese el ID de la agenda medica: ";
    cin >> _idAgendaMedicos;

    cout << "Ingrese el ID del paciente: ";
    cin >> _idPaciente;

    cin.ignore();

    cout << "Ingrese el motivo del turno: ";
    cin.getline(_motivo, 300);

    _estado = true;
}

void Turnos::Mostrar(){
    cout << "ID Turno: " << _idTurno << endl;
    cout << "ID Agenda Medica: " << _idAgendaMedicos << endl;
    cout << "ID Paciente: " << _idPaciente << endl;
    cout << "Motivo: " << _motivo << endl;

    if(_estado == true){
        cout << "Estado: Activo" << endl;
    }
    else{
        cout << "Estado: Inactivo" << endl;
    }

    cout << "-----------------------------" << endl;
}

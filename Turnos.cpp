#include <iostream>
#include "Turnos.h"
#include "ArchivoTurnos.h"
#include <cstring>
#include<cstdio>

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

void Turnos::setFechaTurno(Fecha f)
{
    _fechaTurno.setAnio(f.getAnio());
    _fechaTurno.setMes(f.getMes());
    _fechaTurno.setDia(f.getDia());
}

void Turnos::setHoraTurno(Hora h){
_horaTurno = h;
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

Fecha Turnos::getFechaTurno(){
    return _fechaTurno;
}

Hora Turnos::getHoraTurno(){
return _horaTurno;
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
    char motivo[300];
    cout << "Ingrese el motivo del turno: ";
    cin.ignore();
    cin.getline(motivo,300);
    setMotivo(motivo);
    cout << "ingrese la fecha del turno: " << endl;
    _fechaTurno.CargarFecha();

    cout << "ingrese el horario del turno: " << endl;
    _horaTurno.Cargar();
    _estado = true;
}

void Turnos::Mostrar(){
    cout << "ID Turno: " << _idTurno << endl;
    cout << "ID Agenda Medica: " << _idAgendaMedicos << endl;
    cout << "ID Paciente: " << _idPaciente << endl;
    cout << "Motivo: " << _motivo << endl;
    cout << "Fecha: " << _fechaTurno.toString() << endl;
    cout << "hora: " << _horaTurno.toString()<< endl;

    if(_estado == true){
        cout << "Estado: Activo" << endl;
    }
    else{
        cout << "Estado: Inactivo" << endl;
    }

    cout << "-----------------------------" << endl;
}



void Turnos::cargarModificado(){
        cout << "----------------------------" << endl;
        cout << "ingrese el turno modificado: " << endl;


        cout << "Ingrese el ID de la agenda medica: ";
        cin >> _idAgendaMedicos;

        cout << "Ingrese el ID del paciente: ";
        cin >> _idPaciente;
        char motivo[300];
        cout << "Ingrese el motivo del turno: ";
        cin.ignore();
        cin.getline(motivo,300);
        setMotivo(motivo);
        cout << "ingrese la fecha del turno: " << endl;
        _fechaTurno.CargarFecha();

        cout << "ingrese el horario del turno: " << endl;
        _horaTurno.Cargar();
        _estado = true;
}

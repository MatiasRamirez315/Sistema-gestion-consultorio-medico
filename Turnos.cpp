#include <iostream>
#include "Turnos.h"
#include "ArchivoTurnos.h"
#include <cstring>
#include<cstdio>
#include "ArchivoAgendaMedico.h"
#include "AgendaMedico.h"
#include "Consultorios.h"
#include "Validaciones.h"
#include "ArchivoMedicos.h"
#include "ArchivoPaciente.h"
#include "ArchivoConsultorios.h"

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

void Turnos::setIdConsultorio(int idConsultorio){
_idConsultorio = idConsultorio;
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

int Turnos::getIdConsultorio(){
return _idConsultorio;
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
    ArchivoTurnos archivoTurnos;
    ArchivoAgendaMedicos archivoAgenda;
    AgendaMedicos agenda;
    ArchivoMedicos archivoMedicos;
    ArchivoConsultorios archivoConsultorios;
    ArchivoPaciente archivoPacientes;
    bool Ocupado;
    int idMedico;
    bool fechaOk = 0;

    _idTurno = archivoTurnos.getNuevoId();
    do{
        do{
            cout << "Ingrese el ID del medico: ";
            idMedico = obtenerEnteroValidado(" ");

            if (!archivoMedicos.Existe(idMedico)){
                cout << "El medico no existe..." << endl;
            }
        }while(!archivoMedicos.Existe(idMedico));

        do{
            cout << "Ingrese el ID del consultorio: ";
            _idConsultorio = obtenerEnteroPositivo(" ");

            if (!archivoConsultorios.Existe(_idConsultorio)){
                cout << "El consultorio no existe..." << endl;
            }
        }while(!archivoConsultorios.Existe(_idConsultorio));

        _idAgendaMedicos = archivoAgenda.getNuevoId();

        agenda.setIdAgendaMedico(_idAgendaMedicos);
        agenda.setIdMedico(idMedico);
        agenda.setIdConsultorio(_idConsultorio);

        do{
            cout << "Ingrese la fecha del turno: " << endl;
            _fechaTurno.CargarFecha();
            fechaOk = FechaMayorIgualActual(_fechaTurno);
            if (fechaOk == false){
                cout << "No se puede agendar un turno en el pasado! Intente nuevamente..." << endl;
            }
        }while (fechaOk == false);

        cout << "Ingrese el horario del turno: " << endl;
        _horaTurno.Cargar();

        agenda.setFecha(_fechaTurno);
        agenda.setHorario(_horaTurno);

        agenda.setEstado(true);



        Ocupado = archivoAgenda.EstaOcupado(_idConsultorio, _fechaTurno, _horaTurno);


        if (Ocupado == true ){
              cout << "Ese consultorio ya esta ocupado en ese horario." << endl;
        }


    }while (Ocupado == true);
    archivoAgenda.guardar(agenda);

    do{
        cout << "Ingrese el ID del paciente: ";
        _idPaciente = obtenerEnteroValidado(" ");

        if (!archivoPacientes.Existe(_idPaciente)){
            cout << "El paciente no existe..." << endl;
        }
    }while(!archivoPacientes.Existe(_idPaciente));


    char motivo[300];

    cout << "Ingrese el motivo del turno: ";
    cin.ignore();
    cin.getline(motivo,300);

    setMotivo(motivo);

    _estado = true;
}

void Turnos::Mostrar(){
    cout << "ID Turno: " << _idTurno << endl;
    cout << "ID Agenda Medica: " << _idAgendaMedicos << endl;
    cout << "ID Paciente: " << _idPaciente << endl;
    cout << "Motivo del turno: " << _motivo << endl;
    cout << "Fecha del turno: " << _fechaTurno.toString() << endl;
    cout << "Hora del turno: " << _horaTurno.toString()<< endl;

    if(_estado == true){
        cout << "Estado del turno: Activo" << endl;
    }
    else{
        cout << "Estado del turno: Inactivo" << endl;
    }

    cout << "-----------------------------" << endl;
}



void Turnos::cargarModificado(){

    ArchivoAgendaMedicos archivoAgenda;
    AgendaMedicos agenda;

    int idMedico;
    int idConsultorio;

    cout << "----------------------------" << endl;
    cout << "Ingrese el turno modificado: " << endl;

    cout << "Ingrese el ID del medico: ";
    cin >> idMedico;

    cout << "Ingrese el ID del consultorio: ";
    cin >> idConsultorio;

    _idAgendaMedicos = archivoAgenda.getNuevoId();

    agenda.setIdAgendaMedico(_idAgendaMedicos);
    agenda.setIdMedico(idMedico);
    agenda.setIdConsultorio(idConsultorio);

    cout << "Ingrese la fecha del turno: " << endl;
    _fechaTurno.CargarFecha();

    cout << "Ingrese el horario del turno: " << endl;
    _horaTurno.Cargar();

    agenda.setFecha(_fechaTurno);
    agenda.setHorario(_horaTurno);
    agenda.setEstado(true);

    archivoAgenda.guardar(agenda);

    cout << "Ingrese el ID del paciente: ";
    cin >> _idPaciente;

    char motivo[300];

    cout << "Ingrese el motivo del turno: ";
    cin.ignore();
    cin.getline(motivo,300);

    setMotivo(motivo);

    _estado = true;
}

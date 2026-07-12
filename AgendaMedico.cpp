#include "AgendaMedico.h"
#include "Medico.h"
#include "ArchivoMedicos.h"
#include "ArchivoTurnos.h"
#include "ArchivoAgendaMedico.h"
#include <iostream>
using namespace std;

void AgendaMedicos::setIdAgendaMedico(int idAgenda){
_idAgendaMedico = idAgenda;
}

void AgendaMedicos::setIdMedico(int idMed){
_idMedico = idMed;
}

void AgendaMedicos::setIdConsultorio(int idCons){
_idConsultorio = idCons;
}

void AgendaMedicos::setFecha(Fecha fecha){
_fecha.setAnio(fecha.getAnio());
_fecha.setMes(fecha.getMes());
_fecha.setDia(fecha.getDia());
}

void AgendaMedicos::setHorario(Hora horario){
_horario.setHora(horario.getHora());
_horario.setMinutos(horario.getMinutos());
}

void AgendaMedicos::setEstado(bool estado){
_estado = estado;
}

// GETTERS
int AgendaMedicos::getIdAgendaMedico(){
return _idAgendaMedico;
}

int AgendaMedicos::getIdMedico() {
return _idMedico;
}

int AgendaMedicos::getIdConsultorio(){
return _idConsultorio;
}

Fecha AgendaMedicos::getFecha() {
return _fecha;
}

Hora AgendaMedicos::getHorario(){
return _horario;
}

bool AgendaMedicos::getEstado() {
return _estado;
}

void AgendaMedicos::Mostrar(int idMedico, Fecha fecha){
    Medico med;
    ArchivoMedicos arcMed;
    ArchivoAgendaMedicos arcAgenda;
    ArchivoTurnos arcTurnos;

    AgendaMedicos agenda;

    int pos = arcMed.BuscarPosXID(idMedico);

    if(pos == -1){
        cout << "Medico no encontrado..." << endl;
        return;
    }

    med = arcMed.leer(pos);

    cout << "==================================" << endl;
    cout << "DR. " << med.getNombre() << " " << med.getApellido() << endl;
    cout << "Fecha: " << fecha.toString() << endl;
    cout << "==================================" << endl;

    int cantidad = arcAgenda.getCantRegistros();
    bool encontro = false;

    for(int i = 0; i < cantidad; i++){

        agenda = arcAgenda.leer(i);

        if(
            agenda.getEstado() &&
            agenda.getIdMedico() == idMedico &&
            agenda.getFecha() == fecha &&
            !arcTurnos.ExisteTurnoActivoPorAgenda(
                agenda.getIdAgendaMedico())
        ){

            encontro = true;

            cout << "ID Agenda: "
                 << agenda.getIdAgendaMedico()
                 << endl;

            cout << "Consultorio: "
                 << agenda.getIdConsultorio()
                 << endl;

            cout << "Hora: "
                 << agenda.getHorario().toString()
                 << endl;

            cout << "-----------------------------"
                 << endl;
        }

    }

    if(!encontro){
        cout << "No existen horarios disponibles para ese medico."
             << endl;
    }
}

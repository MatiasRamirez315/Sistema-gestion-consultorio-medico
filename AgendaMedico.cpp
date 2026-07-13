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
    int pos = 0;

    pos = arcMed.BuscarPosXID(idMedico);
    if(pos == -1)
    {
        cout << "Medico no encontrado..." << endl;
        return;
    }

    med = arcMed.leer(pos);

    cout << "==================================" << endl;
    cout << "DR. " << med.getNombre() << " " <<  med.getApellido() << endl;
    cout << fecha.toString() << endl;
    cout << "==================================" << endl;

    for(int bloque=0; bloque<18; bloque++)
    {
        int hora = 8 + bloque/2;
        int minuto = (bloque%2)*30;

        cout << hora << ":";

        if(minuto==0){
            cout << "00";
        }
        else{
            cout << "30";
        }

        if(estaOcupado(idMedico, fecha, hora, minuto)){
            cout << "   Ocupado";
        }
        else{
            cout << "   Disponible";
        }

        cout << endl;
    }
}

bool AgendaMedicos::estaOcupado(int idMedico, Fecha fecha, int hora, int minuto){
    ArchivoTurnos arcTurno;
    Turnos turno;
    AgendaMedicos agenda;
    ArchivoAgendaMedicos arcAgenda;
    int pos = 0;

    int cantidad = arcTurno.contarRegistros();

    for(int i=0; i<cantidad; i++)
    {
        turno = arcTurno.leer(i);
        pos = arcAgenda.BuscarPosXID(turno.getIdAgendaMedico());
        agenda = arcAgenda.leer(pos);

        if(agenda.getEstado() &&
           agenda.getIdMedico() == idMedico &&
           agenda.getFecha() == fecha &&
           agenda.getHorario().getHora() == hora &&
           agenda.getHorario().getMinutos() == minuto){
            return true;
        }
    }

    return false;
}

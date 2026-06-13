#include "AgendaMedico.h"
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
_horario.setSegundos(horario.getSegundos());
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

void AgendaMedicos::Cargar(){
    int dia,mes,anio;
    int hora,minutos,segundos;

    cout<<"Ingrese ID de agenda: ";
    cin>>_idAgendaMedico;

    cout<<"Ingrese ID de medico: ";
    cin>>_idMedico;

    cout<<"Ingrese ID de consultorio: ";
    cin>>_idConsultorio;

    cout<<"Ingrese dia: ";
    cin>>dia;

    cout<<"Ingrese mes: ";
    cin>>mes;

    cout<<"Ingrese anio: ";
    cin>>anio;

    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);

    cout<<"Ingrese hora: ";
    cin>>hora;

    cout<<"Ingrese minutos: ";
    cin>>minutos;

    cout<<"Ingrese segundos: ";
    cin>>segundos;

    _horario.setHora(hora);
    _horario.setMinutos(minutos);
    _horario.setSegundos(segundos);

    _estado=true;
}

void AgendaMedicos::Mostrar(){

    cout<<"ID Agenda: "<<_idAgendaMedico<<endl;
    cout<<"ID Medico: "<<_idMedico<<endl;
    cout<<"ID Consultorio: "<<_idConsultorio<<endl;
    cout<<"Fecha: "<<_fecha.toString()<<endl;
    cout<<"Horario: "<<_horario.toString()<<endl;

    if(_estado==true){
    cout<<"Estado: Activo"<<endl;
    }
    else{
    cout<<"Estado: Inactivo"<<endl;
    }
    cout<<"-----------------------------"<<endl;
}

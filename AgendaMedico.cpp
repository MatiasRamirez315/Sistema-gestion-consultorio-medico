#include "AgendaMedico.h"

void AgendaMedicos::setIdAgendaMedico(int idAgenda){
_idAgendaMedico = idAgenda;
};

void AgendaMedicos::setIdMedico(int idMed){
_idMedico = idMed;
};

void AgendaMedicos::setIdConsultorio(int idCons){
_idConsultorio = idCons;
};

void AgendaMedicos::setFecha(Fecha fecha){
_fecha.setAnio(fecha.getAnio());
_fecha.setMes(fecha.getMes());
_fecha.setDia(fecha.getDia());
};

void AgendaMedicos::setHorario(Hora horario){
_horario.setHora(horario.getHora());
_horario.setMinutos(horario.getMinutos());
_horario.setSegundos(horario.getSegundos());
};

void AgendaMedicos::setEstado(bool estado){
_estado = estado;
};

// GETTERS
int AgendaMedicos::getIdAgendaMedico(){
return _idAgendaMedico;
};

int AgendaMedicos::getIdMedico() {
return _idMedico;
};

int AgendaMedicos::getIdConsultorio(){
return _idConsultorio;
};

Fecha AgendaMedicos::getFecha() {
return _fecha;
};

Hora AgendaMedicos::getHorario(){
return _horario;
};

bool AgendaMedicos::getEstado() {
return _estado;
};

void AgendaMedicos::Cargar(){};
void AgendaMedicos::Mostrar(){};

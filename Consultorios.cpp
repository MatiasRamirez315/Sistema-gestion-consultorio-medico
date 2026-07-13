#include "Consultorios.h"
#include "ArchivoConsultorios.h"
#include "Validaciones.h"
#include "ArchivoAgendaMedico.h"
#include "ArchivoTurnos.h"
#include "Turnos.h"
#include <iostream>

using namespace std;

void Consultorios::setIdConsultorio(int id){
    _idConsultorio = id;
}

void Consultorios::setEstado(bool e){
    _estado = e;
}

int Consultorios::getIDConsultorio () {
    return _idConsultorio;
}

bool Consultorios::getEstado(){
    return _estado;
}

void Consultorios::Inicializar(){
    ArchivoConsultorios archivo;

    for (int i = 1; i <= 7; i++) {
        Consultorios consultorio;
        consultorio.setIdConsultorio(i);
        consultorio.setEstado(true);

        archivo.guardar(consultorio);
    }
}

void Consultorios::HabilitarInhabilitar(){
    ArchivoConsultorios archivo;
    Consultorios cons;

    int id;
    int pos;
    int estado;

    MostrarTodos();

    do{
        cout << "Ingrese el ID del consultorio (1 a 7): ";
        id = obtenerEnteroPositivo(" ");

        if (!archivo.Existe(id)){
            cout << "El consultorio no existe..." << endl;
        }
    }while(!archivo.Existe(id));

    pos = archivo.BuscarPosXID(id);

    cons = archivo.leer(pos);

    do{
        cout << "Ingrese el estado (0 = Fuera de servicio / 1 = Habilitado): ";
        estado = obtenerBooleanoValidado(" ");

        if (estado < 0 || estado > 1){
            cout << "Opcion invalida...";
        }
        else{
            cons.setEstado(estado);
            if(archivo.Modificar(cons, pos)){
                cout << "Estado actualizado correctamente." << endl;
            }
            else{
                cout << "Error al actualizar el estado." << endl;
            }
        }
    }while (estado < 0 || estado > 1);
}

void Consultorios::MostrarDisponibilidad(int idConsultorio, Fecha fecha){

    cout << "===============" << endl;
    cout << "CONSULTORIO " << idConsultorio << endl;
    cout << fecha.toString() << endl;
    cout << "===============" << endl;

    for(int bloque = 0; bloque < 18; bloque++){
        int hora = 8 + bloque / 2;
        int minuto = (bloque % 2) * 30;

        cout << hora << ":";

        if(minuto == 0){
            cout << "00";
        }
        else{
            cout << "30";
        }

        if(estaOcupado(idConsultorio, fecha, hora, minuto)){
            cout << "   Ocupado";
        }
        else{
            cout << "   Disponible";
        }

        cout << endl;
    }
}

bool Consultorios::estaOcupado(int idConsultorio, Fecha fecha, int hora, int minuto){
    ArchivoTurnos arcTurno;
    Turnos turno;
    AgendaMedicos agenda;
    ArchivoAgendaMedicos arcAgenda;

    int cantidad = arcTurno.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        turno = arcTurno.leer(i);

        int pos = arcAgenda.BuscarPosXID(turno.getIdAgendaMedico());

        if(pos == -1){
            continue;
        }

        agenda = arcAgenda.leer(pos);

        if(agenda.getEstado() &&
           agenda.getIdConsultorio() == idConsultorio &&
           agenda.getFecha() == fecha &&
           agenda.getHorario().getHora() == hora &&
           agenda.getHorario().getMinutos() == minuto){
            return true;
        }
    }
    return false;
}

void Consultorios::MostrarTodos(){
    ArchivoConsultorios archivo;
    Consultorios cons;
    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){
        cons = archivo.leer(i);
        cout << "El consultorio #" << cons._idConsultorio  << " se encuentra ";
        if (cons.getEstado() == true){
            cout << "habilitado...";
        }
        else{
            cout << "fuera de servicio...";
        }
        cout << endl;
    }
}

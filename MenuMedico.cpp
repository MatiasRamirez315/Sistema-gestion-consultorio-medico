#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "MenuMedico.h"
#include "Medico.h"
#include "ArchivoMedicos.h"
#include "ArchivoAgendaMedico.h"
#include "AgendaMedico.h"
#include "ArchivoTurnos.h"
#include "Turnos.h"
#include "Validaciones.h"
#include "ArchivoConsultorios.h"
using namespace std;

void MenuMedico::menuMedico(){
    ArchivoMedicos archivo;
    Medico medico;
    int op = 1, y = 0;

    do{
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||            MENU MEDICO            ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("             AGREGAR MEDICO            ", 40, 13, y == 0);
        showItem("            MODIFICAR MEDICO           ", 40, 14, y == 1);
        showItem("         CARGAR DISPONIBILIDAD          ",40,15,y == 2);
        showItem("            CONSULTAR AGENDA           ", 40, 16, y == 3);
        showItem("        MOSTRAR TODOS LOS MEDICOS      ", 40, 17, y == 4);
        showItem("          DAR DE BAJA UN MEDICO        ", 40, 18, y == 5);
        rlutil::locate(40, 18);
        std::cout << "---------------------------------------" << std::endl;
        showItem("        VOLVER AL MENU PRINCIPAL       ", 40, 20, y == 6);

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            rlutil::locate(38,13 + y);
            std::cout << " " << std::endl;
            y--;

            if(y < 0)
            {
                y = 0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(38,13 + y);
            std::cout << " " << std::endl;
            y++;

            if(y > 6)
            {
                y = 6;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                medico.Cargar();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                medico.Modificacion();
                system("pause");
                system("cls");
                break;

             case 2:

                system("cls");
                cargarDisponibilidad();
                system("pause");
                system("cls");

                break;

            // Consultar agenda pasó de la posición 2 a la 3.
            case 3:

                system("cls");
                consultarAgenda();
                system("pause");
                system("cls");

                break;

            case 4:

                system("cls");
                medico.MostrarTodos();
                system("pause");
                system("cls");

                break;

            case 5:

                system("cls");
                medico.Eliminar();
                system("pause");
                system("cls");

                break;

            case 6:

                op = 0;
                system("cls");

                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}
// Este método registra un espacio disponible para un médico.
void MenuMedico::cargarDisponibilidad(){

    AgendaMedicos agenda;

    ArchivoAgendaMedicos archivoAgenda;
    ArchivoMedicos archivoMedicos;
    ArchivoConsultorios archivoConsultorios;

    int idMedico;
    int idConsultorio;

    Fecha fecha;
    Hora horario;

    bool fechaValida;
    bool consultorioOcupado;
    bool medicoOcupado;

    // ---------------------------------------------------------
    // VALIDACIÓN DEL MÉDICO
    // ---------------------------------------------------------

    do{
        cout << "Ingrese el ID del medico: ";

        idMedico = obtenerEnteroValidado(" ");

        if(!archivoMedicos.Existe(idMedico)){
            cout << "El medico no existe..." << endl;
        }

    }while(!archivoMedicos.Existe(idMedico));


    // ---------------------------------------------------------
    // VALIDACIÓN DEL CONSULTORIO
    // ---------------------------------------------------------

    do{
        cout << "Ingrese el ID del consultorio: ";

        idConsultorio = obtenerEnteroPositivo(" ");

        if(!archivoConsultorios.Existe(idConsultorio)){
            cout << "El consultorio no existe..." << endl;
        }

    }while(!archivoConsultorios.Existe(idConsultorio));


    // ---------------------------------------------------------
    // VALIDACIÓN DE LA FECHA
    // ---------------------------------------------------------

    do{
        cout << "Ingrese la fecha disponible: " << endl;

        fecha.CargarFecha();

        fechaValida = FechaMayorIgualActual(fecha);

        if(!fechaValida){
            cout << "No se puede cargar una disponibilidad "
                 << "en una fecha pasada."
                 << endl;
        }

    }while(!fechaValida);


    // ---------------------------------------------------------
    // VALIDACIÓN DEL HORARIO
    // ---------------------------------------------------------

    do{
        cout << "Ingrese el horario disponible: " << endl;

        horario.Cargar();

        /*
            EstaOcupado comprueba si ya existe una agenda para
            ese consultorio, fecha y horario.
            Podemos reutilizarlo para evitar que dos
            médicos utilicen el mismo consultorio al mismo tiempo.
        */
        consultorioOcupado = archivoAgenda.EstaOcupado(
            idConsultorio,
            fecha,
            horario
        );
        // También controlamos que el médico no tenga cargada
        // otra disponibilidad en la misma fecha y hora.
        medicoOcupado = false;

        int cantidadAgendas = archivoAgenda.getCantRegistros();

        for(int i = 0; i < cantidadAgendas; i++){

            AgendaMedicos agendaExistente;

            agendaExistente = archivoAgenda.leer(i);

            if(
                agendaExistente.getEstado() &&
                agendaExistente.getIdMedico() == idMedico &&
                agendaExistente.getFecha() == fecha &&
                agendaExistente.getHorario() == horario
            ){
                medicoOcupado = true;
            }
        }


        if(consultorioOcupado){

            cout << "El consultorio ya tiene una disponibilidad "
                 << "registrada en esa fecha y horario."
                 << endl;
        }

        if(medicoOcupado){

            cout << "El medico ya tiene una disponibilidad "
                 << "registrada en esa fecha y horario."
                 << endl;
        }

    }while(consultorioOcupado || medicoOcupado);


    // ---------------------------------------------------------
    // CARGA DEL OBJETO AGENDA
    // ---------------------------------------------------------

    agenda.setIdAgendaMedico(
        archivoAgenda.getNuevoId()
    );

    agenda.setIdMedico(idMedico);

    agenda.setIdConsultorio(idConsultorio);

    agenda.setFecha(fecha);

    agenda.setHorario(horario);

    agenda.setEstado(true);


    // ---------------------------------------------------------
    // GUARDADO EN AGENDA MEDICOS.DAT
    // ---------------------------------------------------------

    if(archivoAgenda.guardar(agenda)){

        cout << endl;
        cout << "Disponibilidad guardada correctamente." << endl;

        cout << "ID Agenda: "
             << agenda.getIdAgendaMedico()
             << endl;

        cout << "Fecha: "
             << agenda.getFecha().toString()
             << endl;

        cout << "Hora: "
             << agenda.getHorario().toString()
             << endl;
    }
    else{

        cout << "No se pudo guardar la disponibilidad." << endl;
    }
}


void MenuMedico::consultarAgenda(){

    int idMedico;

    Fecha fecha;

    AgendaMedicos agenda;
    ArchivoMedicos archivoMedicos;

    int posicion;

    // Utilizamos la validación numérica en lugar de cin directamente.
    cout << "Ingrese el ID del medico: ";

    idMedico = obtenerEnteroValidado(" ");

    posicion = archivoMedicos.BuscarPosXID(idMedico);

    if(posicion == -1){

        cout << "Medico no encontrado..." << endl;

        return;
    }
    do{
        cout << "Ingrese la fecha: " << endl;

        fecha.CargarFecha();

        if(!FechaMayorIgualActual(fecha)){

            cout << "La fecha ingresada no es correcta..."
                 << endl;
        }

    }while(!FechaMayorIgualActual(fecha));

    agenda.Mostrar(idMedico, fecha);
}

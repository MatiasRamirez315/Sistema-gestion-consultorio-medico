#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "MenuConsultorios.h"
#include "Consultorios.h"
#include "ArchivoConsultorios.h"
#include "Validaciones.h"

void MenuConsultorios::menuConsultorios(){
    ArchivoConsultorios archivo;
    Consultorios cons;

    if (archivo.contarRegistros() == 0){
        cons.Inicializar();
    }

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||         MENU CONSULTORIOS         ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("           LISTAR CONSULTORIOS         ", 40, 13, y == 0);
        showItem("   HABILITAR/INHABILITAR CONSULTORIO   ", 40, 14, y == 1);
        showItem("         CONSULTAR DISPONIBILIDAD      ", 40, 15, y == 2);

        rlutil::locate(40, 16);
        std::cout << "---------------------------------------" << std::endl;
        showItem("               VOLVER                  ", 40, 17, y == 3);

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

            if(y > 3)
            {
                y = 3;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                cons.MostrarTodos();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                cons.HabilitarInhabilitar();
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                ConsultarDisponibilidad();
                system("pause");
                system("cls");
                break;

            case 3:
                op = 0;
                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}

void MenuConsultorios::ConsultarDisponibilidad(){
    int idConsultorio;
    Fecha fecha;
    Consultorios cons;
    ArchivoConsultorios arcCons;

    cout << "Ingrese el ID del consultorio: ";
    cin >> idConsultorio;

    if(!arcCons.Existe(idConsultorio))
    {
        cout << "Consultorio no encontrado..." << endl;
        return;
    }

    do{
        cout << "Ingrese la fecha: " << endl;
        fecha.CargarFecha();
        if (FechaMayorIgualActual(fecha) == false){
            cout << "La fecha ingresada no es correcta.."<< endl;
        }
    }while (FechaMayorIgualActual(fecha) == false);
    cons.MostrarDisponibilidad(idConsultorio, fecha);
}

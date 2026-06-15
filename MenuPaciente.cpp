#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "Paciente.h"
#include "MenuPaciente.h"
#include "ArchivoPaciente.h"
#include "HistoriaClinica.h"

void MenuPaciente::menuPaciente(){
    Paciente paciente;
    HistoriaClinica HC;

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||           MENU PACIENTE           ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("            AGREGAR PACIENTE           ", 40, 13, y == 0);
        showItem("           MODIFICAR PACIENTE          ", 40, 14, y == 1);
        showItem("       CONSULTAR HISTORIA CLINICA      ", 40, 15, y == 2);
        showItem("       MOSTRAR TODOS LOS PACIENTES     ", 40, 16, y == 3);
        showItem("         DAR DE BAJA UN PACIENTE       ", 40, 17, y == 4);
        rlutil::locate(40, 18);
        std::cout << "---------------------------------------" << std::endl;
        showItem("        VOLVER AL MENU PRINCIPAL       ", 40, 19, y == 5);

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

            if(y > 5)
            {
                y = 5;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                paciente.CargarPaciente();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                /// LLAMADO FUNC MODIFICAR PAC
                paciente.Modificacion();
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                /// LLAMADO FUNC CONSULTAR HIST CLIN
                HC.MostrarTodoPaciente();
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                paciente.MostrarTodos();
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                paciente.Eliminar();
                system("pause");
                system("cls");
                break;

            case 5:
                op = 0;
                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}

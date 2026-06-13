#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "MenuHistoriaClinica.h"
#include "HistoriaClinica.h"
#include "ArchivoHistoriaClinica.h"

void MenuHistoriaClinica::menuHistoriaClinica(){
    ArchivoHistoriaClinica archivo;
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
        std::cout << "||      MENU HISTORIA CLINICA        ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("        AGREGAR HISTORIA CLINICA       ", 40, 13, y == 0);
        showItem("   MOSTRAR TODAS LAS HISTORIA CLINICA  ", 40, 14, y == 1);
        showItem(" MOSTRAR HISTORIA CLINICA POR PACIENTE ", 40, 15, y == 2);

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
                HC.Cargar();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                /// LLAMADO FUNC MODIFICAR MED
                HC.MostrarTodas();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                /// LLAMADO FUNC MODIFICAR MED
                HC.MostrarTodoPaciente();
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


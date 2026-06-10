#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "MenuObrasSociales.h"
#include "ObraSociales.h"


void MenuObrasSociales::menuObrasSociales(){
    ObraSociales OS;
    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||        MENU OBRAS SOCIALES        ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("          AGREGAR OBRA SOCIAL          ", 40, 13, y == 0);
        showItem("         MODIFICAR OBRA SOCIAL         ", 40, 14, y == 1);
        showItem("         CONSULTAR FACTURACION         ", 40, 15, y == 2);
        showItem("    MOSTRAR TODAS LAS OBRAS SOCIALES   ", 40, 16, y == 3);
        showItem("      DAR DE BAJA UNA OBRA SOCIAL      ", 40, 17, y == 4);
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
                OS.Cargar();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                OS.Modificacion();
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                OS.MostrarFacturacion();
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                OS.MostrarTodas();
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                OS.Eliminar();
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

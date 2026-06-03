#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "MenuMedico.h"
#include "Medico.h"

void MenuMedico::menuMedico(){
    Medico medico;
    int op = 1, y = 0;

    do
    {
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
        showItem("            CONSULTAR AGENDA           ", 40, 15, y == 2);
        showItem("        MOSTRAR TODOS LOS MEDICOS      ", 40, 16, y == 3);
        showItem("          DAR DE BAJA UN MEDICO        ", 40, 17, y == 4);
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
                medico.Cargar(); /// LLAMADO FUNC CARGAR MED
                medico.Mostrar();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                /// LLAMADO FUNC MOSTRAR MED
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                /// LLAMADO FUNC CONSULTAR AGENDA
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                /// LLAMADO FUNC LISTAR TODOS LOS MED
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                /// LLAMADO FUNC ELIMINAR MED
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

#include <iostream>
#include "rlutil.h"
#include "showItem.h"
#include "MenuConsultorios.h"
#include "Consultorios.h"
#include "ArchivoConsultorios.h"

void MenuConsultorios::menuConsultorios(){
    ArchivoConsultorios archivo;
    Consultorios cons;
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
        showItem("           AGREGAR CONSULTORIO         ", 40, 13, y == 0);
        showItem("           MOSTRAR CONSULTORIOS        ", 40, 14, y == 1);

        rlutil::locate(40, 15);
        std::cout << "---------------------------------------" << std::endl;
        showItem("               VOLVER                  ", 40, 16, y == 2);

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

            if(y > 2)
            {
                y = 2;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                cons.Cargar();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                cons.MostrarTodos();
                system("pause");
                system("cls");
                break;

            case 2:
                op = 0;
                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}

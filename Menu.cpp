#include "Menu.h"
#include "rlutil.h"
#include "showItem.h"
#include <iostream>

using namespace std;

void Menu::menuPrincipal(){

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||          MENU PRINCIPAL           ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("            MENU MEDICOS               ", 40, 13, y == 0);
        showItem("            MENU PACIENTES             ", 40, 14, y == 1);
        showItem("            MENU OBRAS SOCIALES        ", 40, 15, y == 2);
        showItem("            MENU TURNOS                ", 40, 16, y == 3);
        showItem("            MENU ESPECIALIDADES        ", 40, 17, y == 4);
        rlutil::locate(40, 18);
        std::cout << "---------------------------------------" << std::endl;
        showItem("                 SALIR                 ", 40, 19, y == 5);

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
                _menuMedico.menuMedico();
                break;

            case 1:
                system("cls");
                _menuPaciente.menuPaciente();
                break;

            case 2:
                system("cls");
                _menuObrasSociales.menuObrasSociales();
                break;

            case 3:
                system("cls");
                _menuTurnos.menuTurnos();
                break;
            case 4:
                system("cls");
                _menuEspecialidades.menuEspecialidades();
                break;

            case 5:
                op = 0;
                break;

            }
        }
    }

    while(op != 0);

    return;
}
/**
void Menu::CrearUsuario(mail,contrasenia){

   usuario U;
    u.set(mail);
    u.setpass (contra);

    cout << "rol";
    if (rol == 'm'){
        //medico.cargar();
    }

//archivoUsuario.guardar();
return;


}*/

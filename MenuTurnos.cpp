#include "MenuTurnos.h"
#include "rlutil.h"
#include "showItem.h"
#include <iostream>

using namespace std;

void MenuTurnos::menuTurnos(){

    int op=1,y=0;

    do{

        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40,10);
        cout<<"+=====================================+"<<endl;
        rlutil::locate(40,11);
        cout<<"||            MENU TURNOS             ||"<<endl;
        rlutil::locate(40,12);
        cout<<"+=====================================+"<<endl;

        showItem("             PEDIR TURNO              ",40,13,y==0);
        showItem("             LISTAR TURNOS            ",40,14,y==1);

        rlutil::locate(40,15);
        cout<<"---------------------------------------"<<endl;

        showItem("               VOLVER                 ",40,16,y==2);

        int key=rlutil::getkey();

        switch(key){

        case 14:
            y--;
            if(y<0)y=0;
            break;

        case 15:
            y++;
            if(y>2)y=2;
            break;

        case 1:

            switch(y){

            case 0:
                system("cls");
                pedirTurno();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                listarTurnos();
                system("pause");
                system("cls");
                break;

            case 2:
                op=0;
                system("cls");
                break;
            }
            break;
        }

    }while(op!=0);
}

void MenuTurnos::pedirTurno(){

    Turnos turno;
    ArchivoTurnos archivo;

    turno.Cargar();

    if(archivo.guardar(turno)){
        cout<<"Turno guardado correctamente."<<endl;
    }
    else{
        cout<<"No se pudo guardar el turno."<<endl;
    }
}

void MenuTurnos::listarTurnos(){

    ArchivoTurnos archivo;
    Turnos turno;

    int cantidad=archivo.contarRegistros();

    if(cantidad==0){
        cout<<"No hay turnos cargados."<<endl;
        return;
    }

    for(int i=0;i<cantidad;i++){

        turno=archivo.leer(i);

        if(turno.getEstado()){
            turno.Mostrar();
        }
    }
}

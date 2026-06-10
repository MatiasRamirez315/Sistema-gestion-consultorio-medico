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
        showItem("             MODIFICAR TURNOS            ",40,15,y==2);
        showItem("             ELIMINAR TURNOS            ",40,16,y==3);

        rlutil::locate(40,17);
        cout<<"---------------------------------------"<<endl;

        showItem("               VOLVER                 ",40,18,y==4);

        int key=rlutil::getkey();

        switch(key){

        case 14:
            y--;
            if(y<0)y=0;
            break;

        case 15:
            y++;
            if(y>4)y=4;
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
                system("cls");
                ModificarTurno();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                EliminarTurno();
                system("pause");
                system("cls");
                break;

            case 4:
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

void MenuTurnos::ModificarTurno(){


    ArchivoTurnos archivo;
    Turnos turno;
    int id;
    int pos;

    cout << "ingrese el ID del turno que quiere modificar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);

        if(pos == -1)
    {
        cout << "turno no encontrado.." << endl;
        return;
    }
    else{

        turno = archivo.leer(pos);

        cout << "turno hallado: " << endl;
        turno.Mostrar();


        turno.cargarModificado();

        if (archivo.Modificar (turno,pos)){

            cout << "turno modificado con exito.." << endl;
        }
        else{
            cout << "error al modificar el turno.." << endl;
        }

    }


}

void MenuTurnos::EliminarTurno(){


    Turnos turno;
    ArchivoTurnos archivo;
    int id;
    int pos;
    cout << "ingrese el ID del turno que desea eliminar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);


        if(pos == -1)
    {
        cout << "Turno no encontrado.." << endl;
        return;
    }
    else{

        turno = archivo.leer(pos);

        turno.setEstado(false);

        if (archivo.Modificar (turno,pos)){

            cout << "Turno eliminado con exito.." << endl;
        }
        else{
            cout << "error al eliminar el turno.." << endl;
        }
    }


}

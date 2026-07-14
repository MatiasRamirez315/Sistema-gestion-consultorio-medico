#include "MenuTurnos.h"
#include "rlutil.h"
#include "Validaciones.h"
#include "showItem.h"
#include "ArchivoFacturas.h"
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

        showItem("             NUEVO TURNO               ",40,13,y==0);
        showItem("             LISTAR TURNOS             ",40,14,y==1);
        showItem("             MODIFICAR TURNO           ",40,15,y==2);
        showItem("             CANCELAR TURNO            ",40,16,y==3);
        showItem("             CARGAR FACTURA            ",40,17,y==4);
        showItem("             LISTAR FACTURAS           ",40,18,y==5);

        rlutil::locate(40,19);
        cout<<"---------------------------------------"<<endl;

        showItem("        VOLVER AL MENU PRINCIPAL       ", 40, 20, y == 6);

        int key=rlutil::getkey();

        switch(key){

        case 14:
            y--;
            if(y<0)y=0;
            break;

        case 15:
            y++;
            if(y>6)y=6;
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
                system("cls");
                CargarFactura();
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                ListarFacturas();
                system("pause");
                system("cls");
                break;

            case 6:
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
    id = obtenerEnteroValidado(" ");

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


        if (turno.cargarModificado()){
            if (archivo.Modificar (turno,pos)){

                cout << "turno modificado con exito.." << endl;
            }
            else{
                cout << "error al modificar el turno.." << endl;
            }
        }
    }
}

void MenuTurnos::EliminarTurno(){


    Turnos turno;
    ArchivoTurnos archivo;
    int id;
    int pos;
    cout << "ingrese el ID del turno que desea eliminar: ";
    id = obtenerEnteroValidado(" ");

    pos = archivo.BuscarPosXID(id);


        if(pos == -1)
    {
        cout << "Turno no encontrado.." << endl;
        return;
    }
    else{

        turno = archivo.leer(pos);

        turno.Mostrar();

        bool op;

        cout << "esta seguro que desea dar de baja el turno? 1-Si 0-No: ";
        op=obtenerBooleanoValidado("");

        if (op == true){
            turno.setEstado(false);

            if (archivo.Modificar (turno,pos)){

                cout << "Turno eliminado con exito.." << endl;
            }
            else{
                cout << "error al eliminar el turno.." << endl;
            }

        }else{
            cout << "no se dio de baja el turno.. " << endl;
            }
        }
    }

void MenuTurnos::CargarFactura(){
    ArchivoTurnos archivo;
    Turnos turno;
    Facturas factura;
    int id;
    int pos;

    cout << "Ingrese el ID del turno al que desea crear una factura: " << endl;
    id = obtenerEnteroValidado(" ");

    pos = archivo.BuscarPosXID(id);

    if(pos == -1){
        cout << "Turno no encontrado..." << endl;
        return;
    }
    else{
        turno = archivo.leer(pos);
        if(turno.getEstado() == false){
            cout << "Turno no encontrado..." << endl;
        }
        else{
            if (factura.TurnoYaFacturado(turno.getIdTurno()) == false){
                factura.Cargar(turno.getIdTurno());
            }
        }
    }
}

void MenuTurnos::ListarFacturas(){
    ArchivoFacturas archivoF;
    ArchivoTurnos archivoT;
    Facturas factura;
    Turnos turno;
    int cantFacturas = archivoF.contarRegistros();
    int pos = 0;

    if(cantFacturas == 0){
        cout << "No hay facturas." << endl;
        return;
    }

    for(int i=0; i<cantFacturas; i++){
        factura = archivoF.leer(i);
        if(factura.getEstado()){
            pos = archivoT.BuscarPosXID(factura.getIdTurno());
            factura.Mostrar();
            turno = archivoT.leer(pos);
            cout << "Informacion del Turno facturado:" << endl;
            turno.Mostrar();
            cout << "-----------------------------" << endl;
        }
    }
}

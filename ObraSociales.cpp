#include "ObraSociales.h"
#include "ArchivoObraSociales.h"
#include "Validaciones.h"
#include <cstring>
#include <iostream>

using namespace std;

void ObraSociales::setIdObraSocial(int id){
    _idObraSocial = id;
}

void ObraSociales::setNombre(const char *nombre){
    strcpy( _nombre, nombre);
}

void ObraSociales::setPlan(const char* plan){
    strcpy (_plan, plan);
}

void ObraSociales::setTipoCobertura(int tipo){
    _tipoCobertura = tipo;
}

void ObraSociales::setPorcentajeDescuento(float pDescuento){
    _porcentajeDescuento = pDescuento;
}

void ObraSociales::setEstado(bool estado){
    _estado = estado;
}

int ObraSociales::getIdObraSocial(){
	return _idObraSocial;
}

const char* ObraSociales::getNombre(){
	return _nombre;
}

const char* ObraSociales:: getPlan(){
	return _plan;
}

int ObraSociales::getTipoCobertura(){
	return _tipoCobertura;
}

float ObraSociales::getPorcentajeDescuento(){
    return _porcentajeDescuento;
}

bool ObraSociales::getEstado(){
	return _estado;
}

void ObraSociales::Cargar(){
    int id;
    ArchivoObraSociales archivo;
    ObraSociales OS;
    bool ok = false;
    id = archivo.getNuevoId();
    cout << "ID de la Obra social: " << id << endl;
    OS.setIdObraSocial(id);

    do{
        cout << "Ingrese el nombre de la Obra social: ";
        cin.getline(OS._nombre,50);
        ok = esPalabraValida(OS._nombre);
    }while (ok == false);

    ok = false;
     do{
        cout << "Ingrese el nombre del plan: ";
        cin.getline(OS._plan,30);
        ok = esPalabraValida(OS._plan);
    }while (ok == false);

    cout << "Ingrese el tipo de cobertura: ";
    OS._tipoCobertura= obtenerEnteroValidado("");

    cout << "Ingrese el porcentaje de descuento que tendra a la hora de facturar: ";
    OS._porcentajeDescuento = obtenerEnteroValidado("");

    OS._estado = true;


    archivo.guardar(OS);
}

void ObraSociales::Mostrar(){
    cout << "El ID de la Obra social es: " << _idObraSocial << endl;
    cout << "El nombre de la Obra social es: " << _nombre << endl;
    cout << "El plan es: " << _plan << endl;
    cout << "La cobertura es: " << _tipoCobertura << endl;
    cout << "El porcentaje de descuento es: " << _porcentajeDescuento << endl;
    cout << "Estado : " << _estado << endl;
}

void ObraSociales::MostrarTodas(){
    ArchivoObraSociales archivo;
    ObraSociales OS;
    int cantReg = archivo.contarRegistros();

     cout << "ID de la Obra social: 0 " << endl;
     cout << "Nombre: Sin Obra social" << endl << endl;

    for (int i=0;i<cantReg ; i++){
        OS = archivo.leer(i);
        if (OS.getEstado() == true){
            cout << "ID de la Obra social: " << OS.getIdObraSocial()<< endl;
            cout << "Nombre: " << OS.getNombre() << endl;
            cout << "Plan: " << OS.getPlan()<< endl;
            cout << "Tipo de cobertura: " << OS.getTipoCobertura() << endl;
            cout << "Porcentaje de descuento: " << OS.getPorcentajeDescuento() << endl;
            cout << "Estado: " << OS.getEstado() << endl << endl;
        }
    }
}

void ObraSociales::MostrarNombreID(){
    ArchivoObraSociales archivo;
    ObraSociales OS;
    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){
        OS = archivo.leer(i);
        if (OS.getEstado() == true){
            cout << "ID de la Obra social: " << OS.getIdObraSocial()<< endl;
            cout << "Nombre: " << OS.getNombre() << endl;
            cout << "Estado: " << OS.getEstado() << endl;
            cout << "--------------------------------------" << endl;
        }
    }
}


void ObraSociales::Eliminar(){
    ObraSociales OS;
    ArchivoObraSociales archivo;
    int id;
    int pos;
    cout << "Ingrese el ID de la Obra social que desea eliminar: ";
    id = obtenerEnteroValidado("");

    pos = archivo.BuscarPosXID(id);

    if(pos == -1){
        cout << "Obra social no encontrada..." << endl;
        return;
    }
    else{

        OS = archivo.leer(pos);

        OS.Mostrar();

        bool op;
        cout << "esta seguro que desea eliminar esa obra social? 1-Si 0-No: ";
        op =obtenerBooleanoValidado("");

        if (op == true){

            OS.setEstado(false);

            if (archivo.Modificar (OS,pos)){
                cout << "Obra social eliminada con exito..." << endl;
            }
            else{
                cout << "Error al eliminar la Obra social..." << endl;
            }
        }else{
            cout << "no se elimino la obra social.." << endl;
        }
    }
}


void ObraSociales::Modificacion(){
    ArchivoObraSociales archivo;
    ObraSociales OS;
    int id;
    int pos;

    cout << "Ingrese el ID de la Obra social que quiere modificar: ";
    id =obtenerEnteroValidado("");

    pos = archivo.BuscarPosXID(id);

    if(pos == -1){
        cout << "Obra social no encontrada..." << endl;
        return;
    }
    else{

        OS = archivo.leer(pos);

        cout << "Obra social hallada: " << endl;
        OS.Mostrar();


        OS.cargarModificado();

        if (archivo.Modificar (OS,pos)){

            cout << "Obra social modificada con exito..." << endl;
        }
        else{
            cout << "Error al modificar la Obra social..." << endl;
        }

    }
}


void ObraSociales::cargarModificado(){
    cout << "----------------------------" << endl;
    cout << "Ingrese la nueva Obra social: " << endl;
    bool ok = false;

        do{
            cout << "Ingrese el nombre de la Obra social: ";
            cin.getline( _nombre,50);
            ok = esPalabraValida(_nombre);
        }while (ok == false);

     do{
        cout << "Ingrese el nombre del plan: ";
        cin.getline( _plan,30);
        ok = esPalabraValida(_plan);
    }while (ok == false);

    cout << "Ingrese el tipo de cobertura: ";
    _tipoCobertura= obtenerEnteroValidado("");

    cout << "Ingrese el porcentaje de descuento que tendra a la hora de facturar: ";
    _porcentajeDescuento = obtenerEnteroValidado("");

    _estado = true;
}

void ObraSociales::MostrarFacturacion(){
    ArchivoObraSociales archivo;
    ObraSociales OS;
    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){
        OS = archivo.leer(i);
        if (OS.getEstado() == true){
            cout << "Nombre de la Obra social: " << OS.getNombre() << endl;
            cout << "Porcentaje de descuento al facturar: " << OS.getPorcentajeDescuento() << endl << endl;
        }
    }
}

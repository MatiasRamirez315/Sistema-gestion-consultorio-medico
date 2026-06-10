#include "ObraSociales.h"
#include "ArchivoObraSociales.h"
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
    ObraSociales OS;
    cout << "Ingrese el ID de la Obra social: ";
    cin >> OS._idObraSocial;
    cout << "Ingrese el nombre de la Obra social: ";
    cin >> OS._nombre;
    cout << "Ingrese el nombre del plan: ";
    cin >> OS._plan;
    cout << "Ingrese el tipo de cobertura: ";
    cin >> OS._tipoCobertura;
    cout << "Ingrese el porcentaje de descuento que tendra a la hora de facturar: ";
    cin >> OS._porcentajeDescuento;
    OS._estado = true;

    ArchivoObraSociales archivo;

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

void ObraSociales::Eliminar(){
    ObraSociales OS;
    ArchivoObraSociales archivo;
    int id;
    int pos;
    cout << "Ingrese el ID de la Obra social que desea eliminar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);

    if(pos == -1){
        cout << "Obra social no encontrada..." << endl;
        return;
    }
    else{

        OS = archivo.leer(pos);

        OS.setEstado(false);

        if (archivo.Modificar (OS,pos)){
            cout << "Obra social eliminada con exito..." << endl;
        }
        else{
            cout << "Error al eliminar la Obra social..." << endl;
        }
    }
}


void ObraSociales::Modificacion(){
    ArchivoObraSociales archivo;
    ObraSociales OS;
    int id;
    int pos;

    cout << "Ingrese el ID de la Obra social que quiere modificar: ";
    cin >> id;

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

    ObraSociales OS;
    cout << "Ingrese el nombre de la Obra social: ";
    cin>> _nombre;
    cout << "Ingrese el nombre del plan: ";
    cin>> _plan;
    cout << "Ingrese el tipo de cobertura: " ;
    cin >> _tipoCobertura;
    cout << "Ingrese el porcentaje de descuento que tendra a la hora de facturar: ";
    cin >> _porcentajeDescuento;
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

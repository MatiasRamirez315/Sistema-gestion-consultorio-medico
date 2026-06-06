#include "ObraSociales.h"
#include "ArchivoObraSociales.h"
#include <cstring>

void ObraSociales::setIdObraSocial(int id){
_idObraSocial = id;
}
void ObraSociales::setNombre(const char* nombre){
strcpy(_nombre,nombre);
}
void ObraSociales::setPlan(const char* plan){
strcpy(_plan,plan);
}
void ObraSociales::setTipoCobertura(int tipo){
_tipoCobertura = tipo;
}

void ObraSociales::setEstado(bool estado){
_estado = estado;}

// GETTERS
int ObraSociales::getIdObraSocial() {
	return _idObraSocial;
}

const char* ObraSociales::getNombre() {
	return _nombre;
	}

const char*ObraSociales:: getPlan() {
	return _plan;
}

int ObraSociales::getTipoCobertura(){
	return _tipoCobertura;
}

bool ObraSociales::getEstado(){
	return _estado;
}

void ObraSociales::Cargar(){
    ObraSociales OS;
    cout << "ingrese el ID de la Obra social: ";
    cin >>   OS._idObraSocial;
    cout << "ingrese el nombre de la Obra social: ";
    cin>>  OS._nombre;
    cout << "ingrese el nombre del plan: ";
    cin>> OS._plan;
    cout << "Ingrese el tipo de cobertura: " ;
    cin >>  OS._tipoCobertura;
    OS._estado = true;

	 ArchivoObraSociales archivo;

	 archivo.guardar(OS);

};

void ObraSociales::Mostrar(){

    cout << "El ID de la obra social es: " << _idObraSocial << endl;
    cout << "el nombre de la obra social es: " << _nombre << endl;
    cout << "el plan es: " << _plan << endl;
    cout << "la cobertura es: " << _tipoCobertura << endl;
    cout << "estado : " << _estado << endl;


};


void ObraSociales::MostrarTodas(){
ArchivoObraSociales archivo;
ObraSociales OS;
int cantReg = archivo.contarRegistros();

for (int i=0;i<cantReg ; i++){
    OS = archivo.leer(i);

    cout << "ID de la obra social: " << OS.getIdObraSocial()<< endl;
    cout << "Nombre: " << OS.getNombre() << endl;
    cout << "Plan: " << OS.getPlan()<< endl;
    cout << "Tipo de cobertura: " << OS.getTipoCobertura() << endl;
    cout << "Estado: " << OS.getEstado() << endl << endl;

    }
}

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
    std::cout << "ingrese el ID de la Obra social: ";
    std::cin >>   OS._idObraSocial;
	std::cout << "ingrese el nombre de la Obra social: ";
	std::cin>>  OS._nombre;
	std::cout << "ingrese el nombre del plan: ";
	std::cin>> OS._plan;
	std::cout << "Ingrese el tipo de cobertura: " ;
	std::cin >>  OS._tipoCobertura;
    OS._estado = true;

	 ArchivoObraSociales archivo;

	 archivo.guardar(OS);

};

void ObraSociales::Mostrar(){

    std::cout << "El ID de la obra social es: " << _idObraSocial << std::endl;
    std::cout << "el nombre de la obra social es: " << _nombre << std::endl;
    std::cout << "el plan es: " << _plan << std::endl;
    std::cout << "la cobertura es: " << _tipoCobertura << std::endl;
    std::cout << "estado : " << _estado << std::endl;


};

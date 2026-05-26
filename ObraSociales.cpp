#include "ObraSociales.h"
#include <cstring>

void ObraSociales::setIdObraSocial(int id){
_idObraSocial = id;
};
void ObraSociales::setNombre(const char* nombre){
strcpy(_nombre,nombre);
};
void ObraSociales::setPlan(const char* plan){
strcpy(_plan,plan);
};
void ObraSociales::setTipoCobertura(int tipo){
_tipoCobertura = tipo;
};

void ObraSociales::setEstado(bool estado){
_estado = estado;};

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

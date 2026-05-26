#include "HistoriaClinica.h"
#include <cstring>

void HistoriaClinica::setIdHistorial(int id){
_idHistorial = id;
};

void HistoriaClinica::setIdPaciente(int id){
_idPaciente = id;
};

void HistoriaClinica::setDescripcion(const char* descripcion){
strcpy(_descripcion,descripcion);
};

void HistoriaClinica::setEstado(bool estado){
_estado = estado;
};

// GETTERS
int HistoriaClinica::getIdHistorial(){
return _idHistorial;
};

int HistoriaClinica::getIdPaciente(){
return _idPaciente;
};

const char* HistoriaClinica::getDescripcion(){
return _descripcion;
};

bool HistoriaClinica::getEstado(){
return _estado;
};

#include "HistoriaClinica.h"
#include <string>
#include <cstring>

using namespace std;

void HistoriaClinica::setIdHistorial(int id){
_idHistorial = id;
}

void HistoriaClinica::setIdPaciente(int id){
_idPaciente = id;
}

void HistoriaClinica::setDescripcion(string descripcion)
{
_descripcion = descripcion;

}

void HistoriaClinica::setEstado(bool estado){
_estado = estado;
}

// GETTERS
int HistoriaClinica::getIdHistorial(){
return _idHistorial;
}

int HistoriaClinica::getIdPaciente(){
return _idPaciente;
}

string HistoriaClinica::getDescripcion(){
return _descripcion;
}

bool HistoriaClinica::getEstado(){
return _estado;
}

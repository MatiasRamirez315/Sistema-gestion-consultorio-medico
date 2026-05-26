#include "Especialidades.h"
#include <cstring>

void Especialidades::setIdEspecialidad(int id){
    _idEspecialidad = id;
    };

void Especialidades::setDescripcion(const char* desc){
strcpy(_descripcion,desc);
};

void Especialidades::setEstado(bool estado){
     _estado = estado;
      };

int Especialidades::getIdEspecialidad() {
    return _idEspecialidad;
 };
const char* Especialidades::getDescripcion() {
    return _descripcion;
};
bool Especialidades::getEstado(){
    return _estado;
};

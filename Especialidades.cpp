#include "Especialidades.h"
#include <cstring>


using namespace std;

void Especialidades::setIdEspecialidad(int id){
    _idEspecialidad = id;
    }

void Especialidades::setDescripcion(char *descripcion)
{
    strcpy(_descripcion, descripcion);
}

void Especialidades::setEstado(bool estado){
     _estado = estado;
      }

int Especialidades::getIdEspecialidad() {
    return _idEspecialidad;
 }
const char * Especialidades::getDescripcion() {
    return _descripcion;
}
bool Especialidades::getEstado(){
    return _estado;
}

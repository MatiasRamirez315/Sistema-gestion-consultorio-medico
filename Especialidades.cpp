#include "Especialidades.h"
#include <cstring>


using namespace std;

void Especialidades::setIdEspecialidad(int id){
    _idEspecialidad = id;
    }

void Especialidades::setDescripcion(std::string descripcion)
{
    _descripcion = descripcion;
}

void Especialidades::setEstado(bool estado){
     _estado = estado;
      }

int Especialidades::getIdEspecialidad() {
    return _idEspecialidad;
 }
string Especialidades::getDescripcion() {
    return _descripcion;
}
bool Especialidades::getEstado(){
    return _estado;
}

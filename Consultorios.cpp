#include "Consultorios.h"

void Consultorios::setIdConsultorio(int id){
_idConsultorio = id;
}

void Consultorios::setEstado(bool e){
_estado = e;
}

int Consultorios::getIDConsultorio () {
    return _idConsultorio;
}

bool Consultorios::getEstado(){
    return _estado;
    }

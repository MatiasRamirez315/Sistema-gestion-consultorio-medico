#include "Puestos.h"

void Puestos::setIdPuesto(int IDPuesto){
_idPuesto = IDPuesto;
};

void Puestos::setSueldo (float Sueldo){
_sueldo = Sueldo;
};

void Puestos::setEstado(bool estado){
_estado = estado;
};

int Puestos::getIDPuesto(){
    return _idPuesto;
};

float Puestos::getSueldo(){
    return _sueldo;
};

bool Puestos::getEstado(){
    return _estado;
};

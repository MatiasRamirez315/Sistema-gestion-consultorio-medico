#include "Factura.h"

using namespace std;

void Facturas::setIdFactura(int idFac){
_idFactura = idFac;
}

void Facturas::setIdTurno(int idTurno){
_idTurno = idTurno;
}

void Facturas::setFecha(Fecha fecha){
_fecha.setAnio(fecha.getAnio());
_fecha.setMes(fecha.getMes());
_fecha.setDia(fecha.getDia());
}

void Facturas::setImporte(float importe){
_importe = importe;
}

void Facturas::setPagado(bool pagado){
_pagado = pagado;
}

void Facturas::setEstado(bool estado){
_estado = estado;
}

int Facturas::getIdFactura(){
return _idFactura;
}

int Facturas::getIdTurno(){
return _idTurno;
}

Fecha Facturas::getFecha(){
return _fecha;
}

float Facturas::getImporte(){
return _importe;
}

bool Facturas::getPagado(){
return _pagado;
}

bool Facturas::getEstado(){
return _estado;
}

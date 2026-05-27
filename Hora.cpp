#include "Hora.h"

Hora::Hora(){
    _hora = 0;
    _minutos = 0;
    _segundos = 0;
}
Hora::Hora( int hora, int minutos, int segundos){
    _hora = hora;
    _minutos = minutos;
    _segundos = segundos;
}

int Hora::getHora(){
    return _hora;
}

int Hora::getMinutos(){
    return _minutos;
}

int Hora::getSegundos (){
    return _segundos;
}

void Hora::setMinutos(int minutos){
    _minutos = minutos;
}

void Hora::setSegundos(int segundos){
    _segundos = segundos;
}

void Hora::setHora (int hora){
    _hora = hora;
}


string Hora::toString(string formatoHora){
    return to_string(_hora) + ":" + to_string(_minutos) + ":" + to_string(_segundos);
}

#include "Hora.h"
#include "Validaciones.h"

Hora::Hora(){
    _hora = 00;
    _minutos = 00;
    _segundos = 00;
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

void Hora::Cargar(){
    cout << "ingrese la hora (00-23): " << endl;
    _hora = obtenerEnteroValidado("");

    cout << "ingrese los minutos (00-59)" << endl;
     _minutos =obtenerEnteroValidado("");

    cout << "ingrese los segundos (00-59)" << endl;
    _segundos = obtenerEnteroValidado("");
     }



string Hora::toString(string formatoHora){
    return to_string(_hora) + ":" + to_string(_minutos) + ":" + to_string(_segundos);
}

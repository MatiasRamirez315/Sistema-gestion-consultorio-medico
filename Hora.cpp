#include "Hora.h"
#include "Validaciones.h"

Hora::Hora(){
    _hora = 00;
    _minutos = 00;
}
Hora::Hora( int hora, int minutos){
    _hora = hora;
    _minutos = minutos;
}

int Hora::getHora(){
    return _hora;
}

int Hora::getMinutos(){
    return _minutos;
}

void Hora::setMinutos(int minutos){
    _minutos = minutos;
}

void Hora::setHora (int hora){
    _hora = hora;
}

void Hora::Cargar(){
    cout << "Ingrese la hora (08 a 16): " << endl;
    _hora = obtenerHoraValidada();

    cout << "Ingrese los minutos (00/30): " << endl;
    _minutos = obtenerMinutosValidados();
}



string Hora::toString(string formatoHora){
    return to_string(_hora) + ":" + to_string(_minutos);
}

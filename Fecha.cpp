#include "Fecha.h"
#include <iostream>
#include <chrono>
using namespace std;

void Fecha::setCurrentDate() {
    // Obtener la fecha actual del sistema
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&now_c);

    // Asignar los valores a la fecha
    _dia = localTime->tm_mday;
    _mes = localTime->tm_mon + 1; // tm_mon va de 0 a 11
    _anio = localTime->tm_year + 1900; // tm_year es el número de años desde 1900
}


Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

string Fecha::toString(string formatoFecha){
    return to_string(_dia) + "/" + to_string(_mes) + "/" +to_string(_anio);
}

void Fecha::CargarFecha(){
    int d,m,a;
    cout << "ingrese la fecha  " << endl ;
    cout << "dia : ";
    cin >> d;
    cout << "mes : " ;
    cin >>m;
    cout << "anio: ";
    cin >> a;

}

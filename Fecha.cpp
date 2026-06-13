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
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}

void Fecha::CargarFecha(){
bool fechaValidada = false;
    do{


    cout << "Dia: ";
    cin >> _dia;

    cout << "Mes: " ;
    cin >> _mes;

    cout << "Anio: ";
    cin >> _anio;

    if (esFechaValida(_dia, _mes, _anio)){
        fechaValidada = true;
    }
    else
    {
        cout << "fecha invalida. ingrese otra" << endl;
    }
    }while (fechaValidada == false);

}

bool Fecha::esFechaValida(int dia, int mes, int anio) {
  // Verificar el rango del año (asumimos años entre 1900 y 2100)
  if (anio < 1900 || anio > 2100) {
    return false;
  }

  // Verificar el rango del mes (entre 1 y 12)
  if (mes < 1 || mes > 12) {
    return false;
  }

  // Verificar el rango del día en base al mes
  int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)) {
    // Año bisiesto, febrero tiene 29 días
    diasEnMes[1] = 29;
  }
  if (dia < 1 || dia > diasEnMes[mes - 1]) {
    return false;
  }

  return true;
}

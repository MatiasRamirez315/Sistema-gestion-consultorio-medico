#pragma once
#include <iostream>
using namespace std;

class Fecha{
private:
	int _dia, _mes, _anio;

	void establecerFechaPorDefecto();
	bool esBisiesto();
	void agregarDia();

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	void setDia(int dia);
	void setMes (int mes);
	void setAnio(int anio);

	int getDia();
	int getMes();
	int getAnio();
	void agregarDias(int cantidadDias);
	string toString(string formatoFecha = "DD/MM/YYYY");
	 void setCurrentDate();
	 bool esFechaValida(int dia, int mes, int anio);


	 void CargarFecha();

	 bool operator==(Fecha &f){
	     if (f.getDia() == _dia && f.getMes() == _mes && f.getAnio() == _anio) {
                return true;
	     }
	     	 return false;
        }


};

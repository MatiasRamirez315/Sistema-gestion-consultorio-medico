#pragma once
#include <iostream>

using namespace std;

class Hora{
private:
	int _hora, _minutos, _segundos;

	void establecerHoraPorDefecto(); // hay que desarrollar
	bool esHoraValida(); //hay que desarrollar

public:
	Hora();
	Hora(int hora, int minutos);

	int getHora();
	int getMinutos();

	void setHora (int hora);
	void setMinutos(int min);
	void Cargar();
	string toString(string formatoHora = "HH:MM");

	bool operator==(Hora &h){
	if (h.getMinutos() == _minutos && h.getHora() == _hora) {return true;}
	return false;
	}
};


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
	Hora(int hora, int minutos, int segundos);

	int getHora();
	int getMinutos();
	int getSegundos();

	void setHora (int hora);
	void setMinutos(int min);
	void setSegundos (int seg);
	void Cargar();
	string toString(string formatoHora = "HH:MM:SS");

	bool operator==(Hora &h){
	if (h.getSegundos() == _segundos && h.getMinutos() == _minutos && h.getHora() == _hora) {return true;}
	return false;
	}
};


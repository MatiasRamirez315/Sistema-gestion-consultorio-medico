#pragma once
#include "Turnos.h"
#include <cstdio>
#include <string>

class ArchivoTurnos{
private:
	std::string _nombre;

public:
	ArchivoTurnos(std::string _nombre = "Turnos.dat");

	bool guardar(Turnos obj);
	Turnos leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

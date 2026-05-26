#pragma once
#include "Turnos.h"

class ArchivoTurnos{
private:
	char _nombre[30];

public:
	ArchivoTurnos(const char* nombre = "Turnos.dat");

	bool guardar(Turnos obj);
	Turnos leer(int pos);
	int contarRegistros();
};

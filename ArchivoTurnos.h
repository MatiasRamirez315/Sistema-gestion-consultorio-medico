#pragma once
#include "Turnos.h"
#include <cstdio>
class ArchivoTurnos{
private:
	char _nombre[30];

public:
	ArchivoTurnos(const char* _nombre = "Turnos.dat");

	bool guardar(Turnos obj);
	Turnos leer(int pos);
	int contarRegistros();
};

#pragma once
#include "Turnos.h"
#include <cstdio>

class ArchivoTurnos{
private:
	 char _nombre[30];

public:
	ArchivoTurnos();

	bool guardar(Turnos obj);
	Turnos leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

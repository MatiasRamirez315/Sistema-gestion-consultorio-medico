#pragma once
#include "Medico.h"
#include <cstdio>

class ArchivoMedicos{
private:
	char _nombre[30];

public:
	ArchivoMedicos(const char* _nombre = "Medicos.dat");

	bool guardar(Medico obj);
	Medico leer(int pos);
	int contarRegistros();
};


#pragma once
#include "Medico.h"

class ArchivoMedicos{
private:
	char _nombre[30];

public:
	ArchivoMedicos(const char* nombre = "Medicos.dat");

	bool guardar(Medico obj);
	Medico leer(int pos);
	int contarRegistros();
};


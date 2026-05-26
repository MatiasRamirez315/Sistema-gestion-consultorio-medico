#pragma once
#include "Especialidades.h"

class ArchivoEspecialidades{
private:
	char _nombre[30];

public:
	ArchivoEspecialidades(const char* nombre = "Especialidades.dat");

	bool guardar(Especialidades obj);
	Especialidades leer(int pos);
	int contarRegistros();
};


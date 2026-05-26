#pragma once
#include "Especialidades.h"
#include <cstdio>

class ArchivoEspecialidades{
private:
	char _nombre[30];

public:
	ArchivoEspecialidades(const char* _nombre = "Especialidades.dat");

	bool guardar(Especialidades obj);
	Especialidades leer(int pos);
	int contarRegistros();
};


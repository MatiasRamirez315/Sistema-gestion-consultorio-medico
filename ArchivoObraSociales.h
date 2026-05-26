#pragma once
#include "ObraSociales.h"
#include <cstdio>
class ArchivoObraSociales{
private:
	char _nombre[30];

public:
	ArchivoObraSociales(const char* _nombre = "ObrasSociales.dat");

	bool guardar(ObraSociales obj);
	ObraSociales leer(int pos);
	int contarRegistros();
};

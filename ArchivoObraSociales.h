#pragma once
#include "ObraSociales.h"

class ArchivoObraSociales{
private:
	char _nombre[30];

public:
	ArchivoObraSociales(const char* nombre = "ObrasSociales.dat");

	bool guardar(ObraSociales obj);
	ObraSociales leer(int pos);
	int contarRegistros();
};

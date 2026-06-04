#pragma once
#include "ObraSociales.h"
#include <cstdio>
#include <cstring>
class ArchivoObraSociales{
private:
	char _nombre[30];

public:
	ArchivoObraSociales();

	bool guardar(ObraSociales obj);
	ObraSociales leer(int pos);
	int contarRegistros();
};

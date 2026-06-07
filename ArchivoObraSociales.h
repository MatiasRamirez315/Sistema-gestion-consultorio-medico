#pragma once
#include "ObraSociales.h"
#include <cstdio>
#include <cstring>

class ArchivoObraSociales{
private:
	std::string _nombre;

public:
	ArchivoObraSociales();

	bool guardar(ObraSociales obj);
	ObraSociales leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

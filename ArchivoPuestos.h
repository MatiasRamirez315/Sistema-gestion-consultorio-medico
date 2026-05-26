#pragma once
#include "Puestos.h"

class ArchivoPuestos{
private:
	char _nombre[30];

public:
	ArchivoPuestos(const char* nombre = "Puestos.dat");

	bool guardar(Puestos obj);
	Puestos leer(int pos);
	int contarRegistros();
};

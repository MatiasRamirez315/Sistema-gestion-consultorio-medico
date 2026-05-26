#pragma once
#include "Puestos.h"
#include <cstdio>

class ArchivoPuestos{
private:
	char _nombre[30];

public:
	ArchivoPuestos(const char* _nombre = "Puestos.dat");

	bool guardar(Puestos obj);
	Puestos leer(int pos);
	int contarRegistros();
};

#pragma once
#include "Puestos.h"
#include <cstdio>

class ArchivoPuestos{
private:
	char _nombre[30];

public:
	ArchivoPuestos( );

	bool guardar(Puestos obj);
	Puestos leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

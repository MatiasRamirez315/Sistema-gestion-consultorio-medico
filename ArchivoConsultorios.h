#pragma once
#include "Consultorios.h"
#include <cstdio>

class ArchivoConsultorios{
private:
	char _nombre[30];

public:
	ArchivoConsultorios(const char* _nombre = "Consultorios.dat");

	bool guardar(Consultorios obj);
	Consultorios leer(int pos);
	int contarRegistros();
};

#pragma once
#include "Consultorios.h"

class ArchivoConsultorios{
private:
	char _nombre[30];

public:
	ArchivoConsultorios(const char* nombre = "Consultorios.dat");

	bool guardar(Consultorios obj);
	Consultorios leer(int pos);
	int contarRegistros();
};

#pragma once
#include "Consultorios.h"
#include <cstdio>

class ArchivoConsultorios{
private:
	std::string _nombre;

public:
	ArchivoConsultorios(std::string _nombre = "Consultorios.dat");

	bool guardar(Consultorios obj);
	Consultorios leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

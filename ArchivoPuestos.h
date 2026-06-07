#pragma once
#include "Puestos.h"
#include <cstdio>
#include <string>

class ArchivoPuestos{
private:
	std::string _nombre;

public:
	ArchivoPuestos(std::string _nombre = "Puestos.dat");

	bool guardar(Puestos obj);
	Puestos leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

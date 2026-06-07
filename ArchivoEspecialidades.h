#pragma once
#include "Especialidades.h"
#include <cstdio>

class ArchivoEspecialidades{
private:
	std::string _nombre;

public:
	ArchivoEspecialidades(std::string _nombre = "Especialidades.dat");

	bool guardar(Especialidades obj);
	Especialidades leer(int pos);
	int contarRegistros();
	int getNuevoId();
};


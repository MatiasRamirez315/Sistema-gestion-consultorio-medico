#pragma once
#include "Paciente.h"
#include <cstdio>
#include <cstring>
#include <string>

class ArchivoPaciente{
private:
	std::string _nombre;

public:
	ArchivoPaciente();

	bool guardar(Paciente obj);
	Paciente leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

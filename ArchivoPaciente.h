#pragma once
#include "Paciente.h"
#include <cstdio>

class ArchivoPaciente{
private:
	char _nombre[30];

public:
	ArchivoPaciente(const char* _nombre = "Pacientes.dat");

	bool guardar(Paciente obj);
	Paciente leer(int pos);
	int contarRegistros();
};

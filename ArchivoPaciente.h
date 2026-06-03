#pragma once
#include "Paciente.h"
#include <cstdio>
#include <cstring>

class ArchivoPaciente{
private:
	char _nombre[30];

public:
	ArchivoPaciente();

	bool guardar(Paciente obj);
	Paciente leer(int pos);
	int contarRegistros();
};

#pragma once
#include "Paciente.h"

class ArchivoPaciente{
private:
	char _nombre[30];

public:
	ArchivoPaciente(const char* nombre = "Pacientes.dat");

	bool guardar(Paciente obj);
	Paciente leer(int pos);             //**desarrollar */
	int contarRegistros();
};

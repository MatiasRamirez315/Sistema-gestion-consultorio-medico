#pragma once
#include "AgendaMedico.h"

class ArchivoAgendaMedicos{
private:
	char _nombre[30];

public:
	ArchivoAgendaMedicos(const char* nombre = "AgendaMedicos.dat");

	bool guardar(AgendaMedicos obj);
	AgendaMedicos leer(int pos);
	int contarRegistros();
};

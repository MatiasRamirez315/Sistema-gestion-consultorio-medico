#pragma once
#include "AgendaMedico.h"
#include <cstdio>

class ArchivoAgendaMedicos{
private:
	char _nombre[30];

public:
	ArchivoAgendaMedicos(const char* _nombre = "AgendaMedicos.dat");

	bool guardar(AgendaMedicos obj);
	AgendaMedicos leer(int pos);
	int getCantRegistros();
};

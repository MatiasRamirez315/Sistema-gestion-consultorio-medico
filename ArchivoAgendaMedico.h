#pragma once
#include "AgendaMedico.h"
#include <string>
#include <cstdio>

class ArchivoAgendaMedicos{
private:
	char _nombre [30];

public:
	ArchivoAgendaMedicos();

	bool guardar(AgendaMedicos obj);
	AgendaMedicos leer(int pos);
	int getCantRegistros();
	int getNuevoId();
};

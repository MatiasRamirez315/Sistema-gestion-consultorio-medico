#pragma once
#include "AgendaMedico.h"
#include <string>
#include <cstdio>

class ArchivoAgendaMedicos{
private:
	std::string _nombre;

public:
	ArchivoAgendaMedicos(std::string _nombre = "AgendaMedicos.dat");

	bool guardar(AgendaMedicos obj);
	AgendaMedicos leer(int pos);
	int getCantRegistros();
	int getNuevoId();
};

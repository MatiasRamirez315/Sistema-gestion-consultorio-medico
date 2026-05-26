#pragma once
#include "HistoriaClinica.h"
#include <cstdio>

class ArchivoHistoriaClinica{
private:
	char _nombre[30];

public:
	ArchivoHistoriaClinica(const char* _nombre = "HistorialesClinicos.dat");

	bool guardar(HistoriaClinica obj);
	HistoriaClinica leer(int pos);
	int contarRegistros();
};

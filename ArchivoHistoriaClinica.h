#pragma once
#include "HistoriaClinica.h"

class ArchivoHistoriaClinica{
private:
	char _nombre[30];

public:
	ArchivoHistoriaClinica(const char* nombre = "HistorialesClinicos.dat");

	bool guardar(HistoriaClinica obj);
	HistoriaClinica leer(int pos);
	int contarRegistros();
};

#pragma once
#include "HistoriaClinica.h"
#include <cstdio>
#include <string>

class ArchivoHistoriaClinica{
private:
	char _nombre[30];

public:
	ArchivoHistoriaClinica( );

	bool guardar(HistoriaClinica obj);
	HistoriaClinica leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

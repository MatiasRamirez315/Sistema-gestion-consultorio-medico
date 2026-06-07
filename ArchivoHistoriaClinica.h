#pragma once
#include "HistoriaClinica.h"
#include <cstdio>
#include <string>

class ArchivoHistoriaClinica{
private:
	std::string _nombre;

public:
	ArchivoHistoriaClinica(std::string _nombre = "HistorialesClinicos.dat");

	bool guardar(HistoriaClinica obj);
	HistoriaClinica leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

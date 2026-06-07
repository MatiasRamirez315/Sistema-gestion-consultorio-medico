#pragma once
#include "Factura.h"
#include <cstdio>

class ArchivoFacturas{
private:
	std::string _nombre;

public:
	ArchivoFacturas(std::string _nombre = "Facturas.dat");

	bool guardar(Facturas obj);
	Facturas leer(int pos);
	int contarRegistros();
	int getNuevoId();
};

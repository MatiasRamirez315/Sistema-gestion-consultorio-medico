#pragma once
#include "Factura.h"
#include <cstdio>

class ArchivoFacturas{
private:
	char _nombre[30];

public:
	ArchivoFacturas(const char* _nombre = "Facturas.dat");

	bool guardar(Facturas obj);
	Facturas leer(int pos);
	int contarRegistros();
};

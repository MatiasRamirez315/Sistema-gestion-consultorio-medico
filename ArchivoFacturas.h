#pragma once
#include "Factura.h"
class ArchivoFacturas{
private:
	char _nombre[30];

public:
	ArchivoFacturas(const char* nombre = "Facturas.dat");

	bool guardar(Facturas obj);
	Facturas leer(int pos);
	int contarRegistros();
};

#pragma once
#include "Medico.h"
#include <cstdio>
#include <cstring>
#include <string>

class ArchivoMedicos{
private:
	std::string _nombre;

public:
	ArchivoMedicos();
	bool guardar(Medico obj);
	Medico leer(int pos);
	int contarRegistros();
	int getNuevoId();
	bool Modificar (Medico medico, int pos);
    int BuscarPosXID(int id);
};


#pragma once
#include "Medico.h"
#include <cstdio>
#include <cstring>


class ArchivoMedicos{
private:
	 char _nombre[30];

public:
	ArchivoMedicos();
	bool guardar(Medico obj);
	Medico leer(int pos);
	int contarRegistros();
	int getNuevoId();
	bool Modificar (Medico medico, int pos);
    int BuscarPosXID(int id);
    bool Existe(int idMedico);
};


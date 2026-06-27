#pragma once
#include "Consultorios.h"
#include <cstring>

class ArchivoConsultorios{
private:
    char _nombre[30];

public:
	ArchivoConsultorios() ;


	bool guardar(Consultorios obj);
	Consultorios leer(int pos);
	int contarRegistros();
	int getNuevoId();
    bool Modificar(Consultorios cons, int pos);
	int BuscarPosXID (int id);
	bool Existe(int idConsultorio);
};

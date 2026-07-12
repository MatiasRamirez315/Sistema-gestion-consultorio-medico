#pragma once
#include "Turnos.h"
#include <cstdio>

class ArchivoTurnos{
private:
	 char _nombre[30];

public:
	ArchivoTurnos();

	bool guardar(Turnos obj);
	Turnos leer(int pos);
	int contarRegistros();
	int getNuevoId();
	bool Modificar (Turnos turno, int pos);
    int BuscarPosXID(int id);
    // Devuelve true si existe un turno activo
    // asociado al ID de agenda recibido.
    bool ExisteTurnoActivoPorAgenda(int idAgenda);
};

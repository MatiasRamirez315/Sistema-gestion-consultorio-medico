#pragma once
#include "AgendaMedico.h"
#include <string>
#include <cstdio>

class ArchivoAgendaMedicos{
private:
	char _nombre [30];

public:
	ArchivoAgendaMedicos();

	bool guardar(AgendaMedicos obj);
	AgendaMedicos leer(int pos);
	int getCantRegistros();
	int getNuevoId();
    int BuscarPosXID(int id);
    bool Modificar(AgendaMedicos agenda, int pos);

	bool EstaOcupadoConsultorio(int idConsultorio, Fecha fecha, Hora hora, int idAgendaExcluir = -1);
	bool EstaOcupadoMedico(int idMedico, Fecha fecha, Hora hora, int idAgendaExcluir = -1);
};

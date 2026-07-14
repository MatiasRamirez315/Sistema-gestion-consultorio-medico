#pragma once
#include "Fecha.h"
#include "Hora.h"
#include <string>

class Turnos{
private:
		int _idTurno;
		int _idAgendaMedicos;
		int _idPaciente;
		int _idConsultorio;
		Fecha _fechaTurno;
		Hora _horaTurno;
		char _motivo [100];
		bool _estado;
public:
	void setIdTurno(int id);
	void setIdAgendaMedico(int idAgenda);
	void setIdPaciente(int idPaciente);
	void setIdConsultorio (int idConsultorio);
	void setFechaTurno (Fecha fechaTurno);
	void setHoraTurno (Hora horaTurno);
	void setMotivo(const char *motivo);
	void setEstado(bool estado);

	// GETTERS
	int getIdTurno();
	int getIdAgendaMedico() ;
	int getIdPaciente();
	int getIdConsultorio();
	Fecha getFechaTurno();
	Hora getHoraTurno();
	const char *getMotivo() ;
	bool getEstado();

	void Cargar();
	bool cargarModificado();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Modificacion();

};

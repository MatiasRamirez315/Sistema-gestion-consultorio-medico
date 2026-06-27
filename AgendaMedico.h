#pragma once
#include "Hora.h"
#include "Fecha.h"

class AgendaMedicos{
private:
	int _idAgendaMedico;
	int _idMedico;
	int _idConsultorio;
	Fecha _fecha;
	Hora _horario;
	bool _estado;
public:
	void setIdAgendaMedico(int idAgenda);
	void setIdMedico(int idMed);
	void setIdConsultorio(int idCons);
	void setFecha(Fecha fecha);
	void setHorario(Hora horario);
	void setEstado(bool estado);

	// GETTERS
	int getIdAgendaMedico();
	int getIdMedico() ;
	int getIdConsultorio();
	Fecha getFecha() ;
	Hora getHorario();
	bool getEstado() ;

	void Mostrar(int idMedico, Fecha fecha);
	bool estaOcupado(int idMedico, Fecha fecha, int hora, int minuto);
};


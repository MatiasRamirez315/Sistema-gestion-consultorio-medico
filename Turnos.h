#pragma once

class Turnos{
private:
		int _idTurno;
		int _idAgendaMedicos;
		int _idPaciente;
		char _motivo[300];
		bool _estado;
public:
	void setIdTurno(int id);
	void setIdAgendaMedico(int idAgenda);
	void setIdPaciente(int idPaciente);
	void setMotivo(const char* motivo);
	void setEstado(bool estado);

	// GETTERS
	int getIdTurno();
	int getIdAgendaMedico() ;
	int getIdPaciente();
	const char* getMotivo() ;
	bool getEstado();

	void Cargar(); /**hay que desarrollar*/
	void Mostrar();

};

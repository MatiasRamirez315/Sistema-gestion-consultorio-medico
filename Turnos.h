#pragma once
#include <string>

class Turnos{
private:
		int _idTurno;
		int _idAgendaMedicos;
		int _idPaciente;
		std::string _motivo;
		bool _estado;
public:
	void setIdTurno(int id);
	void setIdAgendaMedico(int idAgenda);
	void setIdPaciente(int idPaciente);
	void setMotivo(std::string motivo);
	void setEstado(bool estado);

	// GETTERS
	int getIdTurno();
	int getIdAgendaMedico() ;
	int getIdPaciente();
	std::string getMotivo() ;
	bool getEstado();

	void Cargar(); /**hay que desarrollar*/
	void Mostrar();

};

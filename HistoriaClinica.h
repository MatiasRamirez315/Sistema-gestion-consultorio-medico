#pragma once
#include <string>

class HistoriaClinica{
private:
	int _idHistorial;
	int _idPaciente ;
	std::string _descripcion;
	bool _estado;
public:
	// SETTERS
	void setIdHistorial(int id);
	void setIdPaciente(int id);
	void setDescripcion(std::string descripcion);
	void setEstado(bool estado);

	// GETTERS
	int getIdHistorial();
	int getIdPaciente();
	std::string getDescripcion();
	bool getEstado();
};

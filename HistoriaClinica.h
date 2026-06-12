#pragma once
#include <string>

class HistoriaClinica{
private:
	int _idHistorial;
	int _idPaciente ;
	char _descripcion[300];
	bool _estado;
public:
	// SETTERS
	void setIdHistorial(int id);
	void setIdPaciente(int id);
	void setDescripcion(const char* descripcion);
	void setEstado(bool estado);

	// GETTERS
	int getIdHistorial();
	int getIdPaciente();
	const char* getDescripcion();
	bool getEstado();

	void Cargar();
	void MostrarTodas();
};

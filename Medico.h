#pragma once
#include <string>
#include "Persona.h"
#include "Fecha.h"

class Medico : public Persona{
private:
	int _idMedico;
	int _idPuesto;
	int _idEspecialidad;
	char _matriculaProfesional [12];
	Fecha _fechaIngreso;
	bool _estado;

public:
	void setIdMedico(int id);
	void setIdPuesto(int id);
	void setIdEspecialidad(int id);
	void setMatriculaProfesional(const char *mat);
	void setFechaIngreso(Fecha f);
	void setEstado(bool e);

	// GETTERS
	int getIdMedico();
	int getIdPuesto();
	int getIdEspecialidad();
	const char* getMatriculaProfesional();
	Fecha getFechaIngreso();
	bool getEstado();

	void Cargar();
	void Mostrar();
	void MostrarTodos();
	void Eliminar();

};

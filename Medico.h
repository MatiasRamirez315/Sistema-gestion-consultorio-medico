#pragma once
#include <string>
#include "Persona.h"
#include "Fecha.h"

class Medico : public Persona{
private:
	int _idMedico;
	int _idPuesto;
	int _idEspecialidad;
	std::string _matriculaProfesional;
	Fecha _fechaIngreso;
	bool _estado;

public:
	void setIdMedico(int id);
	void setIdPuesto(int id);
	void setIdEspecialidad(int id);
	void setMatriculaProfesional(std::string mat);
	void setFechaIngreso(Fecha f);
	void setEstado(bool e);

	// GETTERS
	int getIdMedico();
	int getIdPuesto();
	int getIdEspecialidad();
	std::string getMatriculaProfesional();
	Fecha getFechaIngreso();
	bool getEstado();

	void Cargar();
	void Mostrar();

	void MostrarTodos();

	void Eliminar();

};

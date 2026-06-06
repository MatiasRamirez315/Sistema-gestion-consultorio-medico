#pragma once
#include "Persona.h"

class Paciente : public Persona{
private:
	int _idPaciente;
	char _telefono[20];
	char _email [30] ;
	char _genero;
	int _idObraSocial;
	Fecha _fechaNacimiento;
	bool _estado;

public:

	void setIdPaciente(int ID);
	void setTelefono(const char* tel);
	void setEmail(const char* mail);
	void setGenero(char g);
	void setIdObraSocial(int id);
	void setFechaNacimiento(Fecha fechaNac);
	void setEstado(bool estado);

	int getIdPaciente();
	const char* getTelefono();
	const char* getEmail();
	char getGenero();
	int getIdObraSocial();
	Fecha getFechaNac();
	bool getEstado();

	void CargarPaciente();
	void MostrarPaciente();
	void MostrarTodos();

};

#pragma once
#include "Persona.h"
#include <string>

class Paciente : public Persona{
private:
	int _idPaciente;
	std::string _telefono;
	std::string _email ;
	char _genero;
	int _idObraSocial;
	Fecha _fechaNacimiento;
	bool _estado;

public:

	void setIdPaciente(int ID);
	void setTelefono(std::string tel);
	void setEmail(std::string mail);
	void setGenero(char g);
	void setIdObraSocial(int id);
	void setFechaNacimiento(Fecha fechaNac);
	void setEstado(bool estado);

	int getIdPaciente();
	std::string getTelefono();
	std::string getEmail();
	char getGenero();
	int getIdObraSocial();
	Fecha getFechaNac();
	bool getEstado();

	void CargarPaciente();
	void MostrarPaciente();
	void MostrarTodos();
    void Eliminar();
};

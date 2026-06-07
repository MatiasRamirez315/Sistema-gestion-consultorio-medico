#pragma once
#include "Fecha.h"
#include <string>

class Persona{
private:
	std::string _nombre;
	std::string _apellido;
	int _dni;

public:

	void setNombre (std::string nombre);
	void setApellido(std::string apellido);
	void setDNI(int dni);


	std::string getNombre();
	std::string getApellido();
	int getDNI();


	void Cargar(); //no esta desarrollada, capaz no hay que hacerla aca, tengo que ver
	void Mostrar();

};

#pragma once
#include "Fecha.h"

class Persona{
private:
	char _nombre [30];
	char _apellido [30];
	int _dni;
	Fecha _fechaNacimiento;
public:

	void setNombre (const char *nombre);
	void setApellido(const char *apellido);
	void setDNI(int dni);
	void setFechaNacimiento(Fecha fechaNac);

	const char* getNombre();
	const char* getApellido();
	int getDNI();
	Fecha getFechaNac();

	void Cargar(); //no esta desarrollada, capaz no hay que hacerla aca, tengo que ver
	void Mostrar();

};

#pragma once
#include "Fecha.h"
#include <string>

class Persona{
private:
	char _nombre[50];
	char _apellido[50];
	int _dni;

public:

	void setNombre (const char* nombre);
	void setApellido(const char* apellido);
	void setDNI(int dni);


	const char* getNombre();
	const char* getApellido();
	int getDNI();


	void Cargar(); //no esta desarrollada, capaz no hay que hacerla aca, tengo que ver
	void Mostrar();

};

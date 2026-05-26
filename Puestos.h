#pragma once
#include <cstring>

class Puestos{
private:
	int _idPuesto;
	float _sueldo;
	char _descripcion [200];
	bool _estado;
public:

	void setIdPuesto(int IDPuesto);
	void setSueldo (float Sueldo);
	void setDescripcion (const char * descripcion);
	void setEstado(bool estado);

	int getIDPuesto();
	float getSueldo();
	const char * getDescripcion();
	bool getEstado();

};


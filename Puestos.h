#pragma once
#include <cstring>
#include <string>

class Puestos{
private:
	int _idPuesto;
	float _sueldo;
	std::string _descripcion;
	bool _estado;
public:

	void setIdPuesto(int IDPuesto);
	void setSueldo (float Sueldo);
	void setDescripcion (std::string descripcion);
	void setEstado(bool estado);

	int getIDPuesto();
	float getSueldo();
	std::string getDescripcion();
	bool getEstado();

};


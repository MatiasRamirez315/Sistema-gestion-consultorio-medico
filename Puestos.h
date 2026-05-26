#pragma once

class Puestos{
private:
	int _idPuesto;
	float _sueldo;
	bool _estado;
public:

	void setIdPuesto(int IDPuesto);
	void setSueldo (float Sueldo);
	void setEstado(bool estado);

	int getIDPuesto();
	float getSueldo();
	bool getEstado();

};


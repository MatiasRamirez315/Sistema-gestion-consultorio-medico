#pragma once
#include <string>

class Especialidades{
private:
	int _idEspecialidad ;
	std::string _descripcion;
	bool _estado;
public:
	void setIdEspecialidad(int id);
	void setDescripcion(std::string desc);
	void setEstado(bool estado);

	int getIdEspecialidad();
	std::string getDescripcion();
	bool getEstado();
};

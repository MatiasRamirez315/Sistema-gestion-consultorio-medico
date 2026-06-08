#pragma once

class Especialidades{
private:
	int _idEspecialidad ;
	char _descripcion [200];
	bool _estado;
public:
	void setIdEspecialidad(int id);
	void setDescripcion(char *descripcion);
	void setEstado(bool estado);

	int getIdEspecialidad();
	const char * getDescripcion();
	bool getEstado();
};

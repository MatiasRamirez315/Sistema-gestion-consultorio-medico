#pragma once

class Especialidades{
private:
	int _idEspecialidad ;
	char _descripcion[120];
	bool _estado;
public:
	void setIdEspecialidad(int id);
	void setDescripcion(const char* desc);
	void setEstado(bool estado);

	int getIdEspecialidad();
	const char* getDescripcion();
	bool getEstado();
};

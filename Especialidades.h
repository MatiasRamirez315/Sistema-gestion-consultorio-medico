#pragma once

class Especialidades{
private:
	int _idEspecialidad ;
	char _nombre [30];
	char _descripcion [300];
	bool _estado;
public:
	void setIdEspecialidad(int id);
	void setNombre (char* nombre);
	void setDescripcion(char *descripcion);
	void setEstado(bool estado);

	int getIdEspecialidad();
	const char * getNombre();
	const char * getDescripcion();
	bool getEstado();

    int Eleccion();
	void Cargar();
	void Mostrar();
    void MostrarTodas();
    };

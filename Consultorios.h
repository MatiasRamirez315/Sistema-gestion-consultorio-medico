#pragma once
#include "Fecha.h"
#include "Hora.h"

class Consultorios{
private:
	int _idConsultorio;
	bool _estado;

public:
	void setIdConsultorio(int id);
	void setEstado(bool e);


	int getIDConsultorio () ;
	bool getEstado();

    void Cargar();
    void Mostrar();
    void MostrarTodos();

};

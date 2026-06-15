#pragma once
#include "Fecha.h"
#include "Hora.h"

class Consultorios{
private:
	int _idConsultorio;
    Fecha _fechaOcupado;
	Hora _horaOcupado;
	bool _estado;

public:
	void setIdConsultorio(int id);
    void setFechaOcupado (Fecha f);
	void setHoraOcupado (Hora h);
	void setEstado(bool e);


	int getIDConsultorio () ;
    Fecha getFechaOcupado ();
	Hora  getHoraOcupado ();
	bool getEstado();

    void Cargar();
    void Mostrar();
    void MostrarTodos();
    bool Ocupado(Fecha fecha, Hora hora);

};

#pragma once
#include "Fecha.h"
#include "Hora.h"

class Consultorios{
private:
	int _idConsultorio;
	bool _estado; // true = habilitado, false = fuera de servicio

public:
	void setIdConsultorio(int id);
	void setEstado(bool e);


	int getIDConsultorio () ;
	bool getEstado();

    void Inicializar();
    void MostrarTodos();
    void HabilitarInhabilitar();
    void MostrarDisponibilidad(int idConsultorio, Fecha fecha);
    bool estaOcupado(int idConsultorio, Fecha fecha, int hora, int minuto);
};

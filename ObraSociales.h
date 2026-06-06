#pragma once
#include <iostream>

using namespace std;

class ObraSociales{
private:
	int _idObraSocial;
	char _nombre[20];
	char _plan[10];
	int _tipoCobertura ;
	bool _estado;
public:
	void setIdObraSocial(int id);
	void setNombre(const char* nombre);
	void setPlan(const char* plan);
	void setTipoCobertura(int tipo);

	void setEstado(bool estado);

		// GETTERS
	int getIdObraSocial();
	const char* getNombre();
	const char* getPlan() ;
	int getTipoCobertura();
	bool getEstado();

	void Cargar();
	void Mostrar();
	void MostrarTodas();

};


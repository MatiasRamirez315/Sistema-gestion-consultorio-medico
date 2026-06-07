#pragma once
#include <iostream>
#include <string>

using namespace std;

class ObraSociales{
private:
	int _idObraSocial;
	std::string _nombre;
	std::string _plan;
	int _tipoCobertura ;
	bool _estado;

public:
	void setIdObraSocial(int id);
	void setNombre(std::string nombre);
	void setPlan(std::string plan);
	void setTipoCobertura(int tipo);

	void setEstado(bool estado);

		// GETTERS
	int getIdObraSocial();
	std::string getNombre();
	std::string getPlan() ;
	int getTipoCobertura();
	bool getEstado();

	void Cargar();
	void Mostrar();
	void MostrarTodas();

};


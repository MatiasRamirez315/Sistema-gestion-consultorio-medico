#pragma once
#include <iostream>
#include <string>

using namespace std;

class ObraSociales{
private:
	int _idObraSocial;
	char _nombre [50];
	char _plan [30];
	int _tipoCobertura ;
    float _porcentajeDescuento;
	bool _estado;

public:
	void setIdObraSocial(int id);
	void setNombre(const char * nombre);
	void setPlan(const char* plan);
	void setTipoCobertura(int tipo);
    void setPorcentajeDescuento(float pDescuento);
	void setEstado(bool estado);

	int getIdObraSocial();
	const char* getNombre();
	const char* getPlan() ;
	int getTipoCobertura();
	float getPorcentajeDescuento();
	bool getEstado();

	void Cargar();
	void cargarModificado();
	void Mostrar();
	void MostrarTodas();
	void Eliminar();
    void Modificacion();
    void MostrarFacturacion();
    void MostrarNombreID();

};


#pragma once
#include "Fecha.h"
#include "Validaciones.h"

class Facturas{
private:

	int _idFactura;
	int _idTurno ;
	Fecha _fecha;
	float _importe;
	bool _pagado;
	bool _estado;

public:
	void setIdFactura(int idFac);
	void setIdTurno(int idTurno);
	void setFecha(Fecha fecha);
	void setImporte(float importe);
	void setPagado(bool pagado);
	void setEstado(bool estado);

	int getIdFactura();
	int getIdTurno();
	Fecha getFecha();
	float getImporte();
	bool getPagado();
	bool getEstado();

	void Cargar(int idTurno);
	bool TurnoYaFacturado(int idTurno);
	void Mostrar();
};

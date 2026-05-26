#pragma once

class Consultorios{
private:
	int _idConsultorio;
	bool _estado;
public:
	void setIdConsultorio(int id);
	void setEstado(bool e);

	int getIDConsultorio () ;
	bool getEstado();

};

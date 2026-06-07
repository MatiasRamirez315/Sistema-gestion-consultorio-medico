#pragma once
#include "ArchivoPaciente.h"

class ManagerPaciente{
public:
	ManagerPaciente();

   void guardarPaciente();
   void listarPacientes();

private:
   Paciente crearPaciente();
   ArchivoPaciente _repoPacientes;
};

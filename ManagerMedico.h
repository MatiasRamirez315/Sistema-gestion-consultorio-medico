#pragma once
#include "ArchivoMedicos.h"

class ManagerMedico {
public:
	ManagerMedico();

   void guardarMedico();
   void listarMedicos();

private:
   Medico crearMedico();
   ArchivoMedicos _repoMedicos;
};

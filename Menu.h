#pragma once
#include "MenuMedico.h"
#include "MenuPaciente.h"
#include "MenuObrasSociales.h"

class Menu{

private:
    MenuMedico _menuMedico;
    MenuPaciente _menuPaciente;
    MenuObrasSociales _menuObrasSociales;

public:
    void menuPrincipal();

};

#pragma once
#include "MenuMedico.h"
#include "MenuPaciente.h"
#include "MenuObrasSociales.h"
#include "MenuTurnos.h"
#include "MenuEspecialidades.h"

class Menu{

private:
    MenuMedico _menuMedico;
    MenuPaciente _menuPaciente;
    MenuObrasSociales _menuObrasSociales;
    MenuTurnos _menuTurnos;
    MenuEspecialidades _menuEspecialidades;

public:
    void menuPrincipal();

};

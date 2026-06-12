#pragma once
#include "MenuMedico.h"
#include "MenuPaciente.h"
#include "MenuObrasSociales.h"
#include "MenuTurnos.h"
#include "MenuEspecialidades.h"
#include "MenuConsultorios.h"
#include "MenuHistoriaClinica.h"

class Menu{

private:
    MenuMedico _menuMedico;
    MenuPaciente _menuPaciente;
    MenuObrasSociales _menuObrasSociales;
    MenuTurnos _menuTurnos;
    MenuEspecialidades _menuEspecialidades;
    MenuConsultorios _menuConsultorios;
    MenuHistoriaClinica _menuHistoriaClinica; //hay que desarrollar

public:
    void menuPrincipal();

};

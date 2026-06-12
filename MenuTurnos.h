#pragma once
#include "Turnos.h"
#include "ArchivoTurnos.h"
#include "Factura.h"

class MenuTurnos{

public:
    void menuTurnos();
    void pedirTurno();
    void listarTurnos();
    void ModificarTurno();
    void EliminarTurno();
    void CargarFactura();
    void ListarFacturas();
};

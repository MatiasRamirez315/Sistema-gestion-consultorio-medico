#pragma once
#include "ObraSociales.h"
#include "ArchivoObraSociales.h"

class ManagerObraSocial
{
private:
    void agregarObraSocial();


    ArchivoObraSociales _archivoObrasSociales;

public:
    void menuObraSocial();
};

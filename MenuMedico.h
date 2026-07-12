#pragma once

class MenuMedico
{
private:

public:
    void menuMedico();

    /* Permite registrar una fecha y horario disponible
     para un médico en un consultorio.*/
    void cargarDisponibilidad();

    /* Muestra los espacios disponibles de un médico
     para una fecha determinada.*/
    void consultarAgenda();
};

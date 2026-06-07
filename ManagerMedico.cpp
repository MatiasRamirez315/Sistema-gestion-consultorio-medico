#include <iostream>
#include "Medico.h"
#include "ManagerMedico.h"
#include "rlutil.h"

using namespace std;

ManagerMedico::ManagerMedico()
    : _repoMedicos()
{
}

Medico ManagerMedico::crearMedico()
{
    int id = _repoMedicos.getNuevoId();
    string titulo;

    cout << "El codigo es: #" << id << endl;
    cout << "Ingrese titulo: ";
  // titulo = cargarCadena();

    //return Medico(id, titulo, 1); /// objeto anonimo
}

void ManagerMedico::guardarMedico()
{
    Medico reg = crearMedico();
    if(_repoMedicos.guardar(reg))
    {
        cout << "Se guardo exitosamente" << endl;
    }
    else
    {
        cout << "No se pudo guardar" << endl;
    }
}
/*
void ManagerMedico::listarMedicos()
{
    int cantidad = _repoMedicos.getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        Medico med = _repoMedicos.leer(i);
        cout << "-----------------------"<<endl;
        cout << "ID Medico #" << med.getIdMedico() << endl;
        cout << "ID Puesto #" << med.getIdPuesto() << endl;
        cout << "ID Especialidad " << med.getIdEspecialidad() << endl;
        cout << "Matricula Profesional " << med.getMatriculaProfesional() << endl;
        cout << "Fecha Creacion: " <<
             med.getFechaIngreso().getDia()
             << "/" << med.getFechaIngreso().getMes()
             << "/" << med.getFechaIngreso().getAnio() << endl;
    }
}*/

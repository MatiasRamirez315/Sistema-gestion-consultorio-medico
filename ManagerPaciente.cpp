#include <iostream>
#include "Paciente.h"
#include "ManagerPaciente.h"
#include "rlutil.h"

using namespace std;

ManagerPaciente::ManagerPaciente()
    : _repoPacientes()
{
}

Paciente ManagerPaciente::crearPaciente()
{
    int id = _repoPacientes.getNuevoId();
    string titulo;

    cout << "El codigo es: #" << id << endl;
    cout << "Ingrese titulo: ";
    //titulo = cargarCadena();

    //return Medico(id, titulo, 1); /// objeto anonimo
}

void ManagerPaciente::guardarPaciente()
{
    Paciente reg = crearPaciente();
    if(_repoPacientes.guardar(reg))
    {
        cout << "Se guardo exitosamente" << endl;
    }
    else
    {
        cout << "No se pudo guardar" << endl;
    }
}
/*
void ManagerPaciente::listarPacientes()
{
    int cantidad = _repoPacientes.getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        Paciente pac = _repoPacientes.leer(i);
        cout << "-----------------------"<<endl;
        cout << "ID Paciente #" << pac.getIdPaciente() << endl;
        cout << "Telefono " << pac.getTelefono() << endl;
        cout << "Email " << pac.getEmail() << endl;
        cout << "Genero " << pac.getGenero() << endl;
        cout << "ID Obra Social " << pac.getIdObraSocial() << endl;
        cout << "Fecha Creacion: " <<
             pac.getFechaNacimiento().getDia()
             << "/" << pac.getFechaNacimiento().getMes()
             << "/" << pac.getFechaNacimiento().getAnio() << endl;
    }
}
*/

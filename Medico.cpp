#include "Medico.h"
#include "Persona.h"
#include "Fecha.h"
#include "ArchivoMedicos.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void Medico::setIdMedico(int id)
{
    _idMedico = id;
}

void Medico::setIdPuesto(int id)
{
    _idPuesto = id;
}

void Medico::setIdEspecialidad(int id)
{
    _idEspecialidad = id;
}

void Medico::setMatriculaProfesional(const char* matProf)
{
strcpy(_matriculaProfesional,  matProf);

}

void Medico::setFechaIngreso(Fecha f)
{
    _fechaIngreso.setAnio(f.getAnio());
    _fechaIngreso.setMes(f.getMes());
    _fechaIngreso.setDia(f.getDia());
}

void Medico::setEstado(bool e)
{
    _estado = e;
}

int Medico::getIdMedico()
{
    return _idMedico;
}

int Medico::getIdPuesto()
{
    return _idPuesto;
}

int Medico::getIdEspecialidad()
{
    return _idEspecialidad;
}

const char* Medico::getMatriculaProfesional()
{
    return _matriculaProfesional;
}

Fecha Medico::getFechaIngreso()
{
    return _fechaIngreso;
}

bool Medico::getEstado()
{
    return _estado;
}

void Medico::Cargar()
{
    bool op = false;
    Medico medico;
    do
    {
        medico.Persona::Cargar();

        cout << "Ingrese el ID del medico: ";
        cin >>  medico._idMedico;

        cout << "Ingrese el ID del puesto: ";
        cin >> medico. _idPuesto;
        //agregar opciones de tipos de puesto ej: 1---- odontologo.
        cout << "Ingrese el ID de la especialidad: " << endl;

        cout << "1- Clinico" <<endl;
        cout << "2- Oftalmologo" << endl;
        cout << "3- Odontologo" << endl;
        cout << "4- Pediatra" << endl;
        cout << "5- Traumatologo " << endl;
        cout << "6- Dermatologo" << endl;
        cout << "7- Cardiologo" << endl;
        do
        {
            cin >>  medico._idEspecialidad;
            if (medico._idEspecialidad < 1 || medico._idEspecialidad  > 7)
            {
                cout << "Error al elegir la especialidad, vuelva a seleccionar." << endl;
            }
        }
        while (medico._idEspecialidad < 1 || medico._idEspecialidad  > 7 );

        cout << "Ingrese la matricula: ";
        cin >>  medico._matriculaProfesional;
        medico._fechaIngreso.CargarFecha();

        cout << "Desea confirmar sus datos? 1-Si 0-No: ";
        cin >> op;
        if (op== false)
        {
            cin.ignore();
        };
    }
    while(op == false);

    medico.setEstado(true);

    ArchivoMedicos archivo;

    archivo.guardar(medico);

}

void Medico::Mostrar()
{

    Persona::Mostrar();
    cout << "ID del medico :"  << _idMedico << endl;
    cout << "ID del puesto: " << _idPuesto << endl;
    cout << "ID de la especialidad: " << _idEspecialidad << endl;
    cout << "Matricula: " << _matriculaProfesional << endl;
    cout << "Fecha de ingreso: " << _fechaIngreso.toString() << endl;
    cout << "Estado: " << _estado << endl;
}

void Medico::MostrarTodos()
{
    ArchivoMedicos archivo;
    Medico medico;
    int cantReg = archivo.contarRegistros();

    for (int i=0; i<cantReg ; i++)
    {
        medico = archivo.leer(i);
        if (medico.getEstado() == true){
        medico.Persona::Mostrar();
        cout << "ID del medico :"  << medico._idMedico << endl;
        cout << "ID del puesto: " << medico._idPuesto << endl ;
        cout << "ID de la especialidad: " << medico._idEspecialidad << endl;
        cout << "Matricula: " << medico._matriculaProfesional << endl;
        cout << "Fecha de ingreso: " << medico._fechaIngreso.toString() << endl;
        cout << "Estado: " << medico._estado << endl << endl;
        }
    }

}

void Medico::Eliminar()
{
    Medico medico;
    ArchivoMedicos archivo;
    int id;
    int pos;
    cout << "ingrese el ID del medico que desea eliminar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);


        if(pos == -1)
    {
        cout << "medico no encontrado.." << endl;
        return;
    }
    else{

        medico = archivo.leer(pos);

        medico.setEstado(false);

        if (archivo.Modificar (medico,pos)){

            cout << "medico eliminado con exito.." << endl;
        }
        else{
            cout << "error al eliminar el medico.." << endl;
        }
    }
}

void Medico::Modificacion(){

    ArchivoMedicos archivo;
    Medico medico;
    int id;
    int pos;

    cout << "ingrese el ID del medico que quiere modificar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);

        if(pos == -1)
    {
        cout << "medico no encontrado.." << endl;
        return;
    }
    else{

        medico = archivo.leer(pos);

        cout << "medico hallado: " << endl;
        medico.Mostrar();


        medico.cargarModificado();

        if (archivo.Modificar (medico,pos)){

            cout << "medico modificado con exito.." << endl;
        }
        else{
            cout << "error al modificar el medico.." << endl;
        }

    }
}

void Medico::cargarModificado(){
        cout << "----------------------------" << endl;
        cout << "ingrese el nuevo medico: " << endl;

        bool op = false;
    do
    {
        Persona::Cargar();

        cout << "Ingrese el ID del puesto: ";
        cin >> _idPuesto;
        //agregar opciones de tipos de puesto ej: 1---- odontologo.
        cout << "Ingrese el ID de la especialidad: " << endl;

        cout << "1- Clinico" <<endl;
        cout << "2- Oftalmologo" << endl;
        cout << "3- Odontologo" << endl;
        cout << "4- Pediatra" << endl;
        cout << "5- Traumatologo " << endl;
        cout << "6- Dermatologo" << endl;
        cout << "7- Cardiologo" << endl;
        do
        {
            cin >>  _idEspecialidad;
            if (_idEspecialidad < 1 || _idEspecialidad  > 7)
            {
                cout << "Error al elegir la especialidad, vuelva a seleccionar." << endl;
            }
        }
        while (_idEspecialidad < 1 || _idEspecialidad  > 7 );

        cout << "Ingrese la matricula: ";
        cin >>  _matriculaProfesional;
        _fechaIngreso.CargarFecha();

        cout << "Desea confirmar sus datos? 1-Si 0-No: ";
        cin >> op;
        if (op== false)
        {
            cin.ignore();
        };
    }
    while(op == false);

    setEstado(true);
}

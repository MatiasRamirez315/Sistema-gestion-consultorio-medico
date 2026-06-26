#include "Medico.h"
#include "Persona.h"
#include "Fecha.h"
#include "ArchivoMedicos.h"
#include "Especialidades.h"
#include "Validaciones.h"
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
    bool fechaOK;
    bool op = false;
    int id;
    ArchivoMedicos archivo;
    Especialidades esp;
    Medico medico;
    do
    {
        medico.Persona::Cargar();


        id = archivo.getNuevoId();
        medico.setIdMedico(id);
        cout << "ID del medico: " << id << endl;


        cout << "Ingrese el ID del puesto: ";

        medico._idPuesto = obtenerEnteroValidado("");
        //agregar opciones de tipos de puesto ej: 1---- odontologo.
        medico._idEspecialidad =  esp.Eleccion();

        cout << "Ingrese la matricula: ";
        cin >>  medico._matriculaProfesional;

        do{
        cout << "ingrese la fecha en que comenzo a trabajar: " << endl;
        medico._fechaIngreso.CargarFecha();
        fechaOK = FechaMenorIgualActual(_fechaIngreso);
        if (fechaOK == false){
            cout << "error en la fecha.. "<< endl ;
        }
        }while (fechaOK == false);


        cout << "Desea confirmar sus datos? 1-Si 0-No: ";
        op = obtenerBooleanoValidado(" ");

        if (op== false)
        {
            cin.ignore();
        };
    }
    while(op == false);

    medico.setEstado(true);

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
        bool fechaOK;
        Especialidades esp;
        cout << "----------------------------" << endl;
        cout << "ingrese el nuevo medico: " << endl;

        bool op = false;
    do
    {

        Persona::Cargar();

        cout << "Ingrese el ID del puesto: ";
        cin >> _idPuesto;
        //agregar opciones de tipos de puesto ej: 1---- odontologo.

        _idEspecialidad =  esp.Eleccion();

        cout << "Ingrese la matricula: ";
        cin >>  _matriculaProfesional;

        do{
        cout << "ingrese la fecha en que comenzo a trabajar: " << endl;
        _fechaIngreso.CargarFecha();
        fechaOK = FechaMenorIgualActual(_fechaIngreso);
        if (fechaOK == false){
            cout << "error en la fecha.. "<< endl ;
        }
        }while (fechaOK == false);

        cout << "Desea confirmar sus datos? 1-Si 0-No: ";
        op= obtenerBooleanoValidado(" ");
        if (op== false)
        {
            cin.ignore();
        };
    }
    while(op == false);

    setEstado(true);
}

#include "HistoriaClinica.h"
#include "ArchivoHistoriaClinica.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

void HistoriaClinica::setIdHistorial(int id){
_idHistorial = id;
}

void HistoriaClinica::setIdPaciente(int id){
_idPaciente = id;
}

void HistoriaClinica::setDescripcion(const char* descripcion)
{
strcpy(_descripcion, descripcion);

}

void HistoriaClinica::setEstado(bool estado){
_estado = estado;
}

// GETTERS
int HistoriaClinica::getIdHistorial(){
return _idHistorial;
}

int HistoriaClinica::getIdPaciente(){
return _idPaciente;
}

const char * HistoriaClinica::getDescripcion(){
return _descripcion;
}

bool HistoriaClinica::getEstado(){
return _estado;
}

void HistoriaClinica::Cargar(){
    ArchivoHistoriaClinica archivo;
    HistoriaClinica HC;

    int id = archivo.getNuevoId();
    HC.setIdHistorial(id);
    cout << "ID de la historia clinica: " << HC._idHistorial << endl;

    cout << "Ingrese el ID del paciente: " ;
    cin >> HC._idPaciente;

    cout << "Ingrese la descripcion de la consulta: ";
    cin.ignore();

    cin.getline(HC._descripcion,300);

    HC.setEstado(true);

    archivo.guardar(HC);
}

void HistoriaClinica::MostrarTodas(){

    ArchivoHistoriaClinica archivo;
    HistoriaClinica HC;

    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){

        HC = archivo.leer(i);

        cout << "ID " << HC.getIdHistorial() << endl;
        cout << "ID del paciente " << HC.getIdPaciente() << endl;
        cout << "Descripcion: " << HC.getDescripcion() << endl;
        cout << "Estado: " << HC.getEstado() << endl<< endl;
    }
}

void HistoriaClinica::MostrarTodoPaciente(){

    ArchivoHistoriaClinica archivo;
    HistoriaClinica HC;
    int id;
    cout << "ingrese el id del paciente: ";
    cin >> id;

    cout << endl;

    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){

        HC = archivo.leer(i);
        if (HC.getIdPaciente() == id && HC.getEstado() == true){
            cout << "ID " << HC.getIdHistorial() << endl;
            cout << "ID del paciente " << HC.getIdPaciente() << endl;
            cout << "Descripcion: " << HC.getDescripcion() << endl;
            cout << "Estado: " << HC.getEstado() << endl << endl;
        }
    }
}

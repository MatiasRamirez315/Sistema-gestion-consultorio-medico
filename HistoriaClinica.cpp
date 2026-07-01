#include "HistoriaClinica.h"
#include "ArchivoHistoriaClinica.h"
#include "Validaciones.h"
#include "Paciente.h"
#include "ArchivoPaciente.h"
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
    Paciente paciente;
    ArchivoPaciente archivoP;

    int cantReg = archivo.contarRegistros();
    int cantRegPaciente = archivo.contarRegistros();


    for (int k = 0;  k<cantRegPaciente ; k++){
            paciente = archivoP.leer(k);
        for (int i=0;i<cantReg ; i++){

            HC = archivo.leer(i);
            if (HC.getIdPaciente() == paciente.getIdPaciente() && HC.getEstado() == true){
                cout << "ID: " << HC.getIdHistorial() << endl;
                cout << "ID del paciente: " << HC.getIdPaciente() << endl;
                cout << "Nombre: " << paciente.getNombre() << endl;
                cout << "Apellido: " << paciente.getApellido() << endl;
                cout << "Obra social: " << paciente.getIdObraSocial() << endl;
                cout << "Descripcion: " << HC.getDescripcion() << endl;
                cout << "Estado: " << HC.getEstado() << endl << endl;
            }
        }
    }
}

void HistoriaClinica::MostrarTodoPaciente(){

    ArchivoHistoriaClinica archivo;
    HistoriaClinica HC;
    Paciente paciente;
    ArchivoPaciente archivoP;
    bool ok = false;
    int id;
    cout << "ingrese el id del paciente: ";
    id = obtenerEnteroValidado(" ");

    cout << endl;

    int cantRegPaciente = archivo.contarRegistros();
    int cantReg = archivo.contarRegistros();

    for (int k = 0;  k<cantRegPaciente ; k++){
            paciente = archivoP.leer(k);

        for (int i=0;i<cantReg ; i++){

            HC = archivo.leer(i);
            if (HC.getIdPaciente() == id && paciente.getIdPaciente() == id&& HC.getEstado() == true){
                cout << "ID: " << HC.getIdHistorial() << endl;
                cout << "ID del paciente: " << HC.getIdPaciente() << endl;
                cout << "Nombre: " << paciente.getNombre() << endl;
                cout << "Apellido: " << paciente.getApellido() << endl;
                cout << "Obra social: " << paciente.getIdObraSocial() << endl;
                cout << "Descripcion: " << HC.getDescripcion() << endl;
                cout << "Estado: " << HC.getEstado() << endl << endl;
                ok =true;
            }
        }
    }
    if (ok == false){
        cout << "no se encontro historia clinica con ese ID de paciente" << endl;
    }
}

#include "Especialidades.h"
#include "ArchivoEspecialidades.h"
#include <iostream>
#include <cstring>


using namespace std;

void Especialidades::setIdEspecialidad(int id){
    _idEspecialidad = id;
    }

void Especialidades::setDescripcion(char *descripcion)
{
    strcpy(_descripcion, descripcion);
}

void Especialidades::setNombre(char *nombre){
    strcpy (_nombre, nombre);
}

void Especialidades::setEstado(bool estado){
     _estado = estado;
      }

int Especialidades::getIdEspecialidad() {
    return _idEspecialidad;
 }
const char * Especialidades::getDescripcion() {
    return _descripcion;
}

const char* Especialidades::getNombre(){
    return _nombre;
}

bool Especialidades::getEstado(){
    return _estado;
}

void Especialidades::Cargar(){
    ArchivoEspecialidades archivo;
    Especialidades esp;
    esp._idEspecialidad = archivo.getNuevoId();
    cout << "ID : " << esp._idEspecialidad << endl;
    cout << "ingrese el nombre: " ;

    cin.getline(esp._nombre,30);

    cout << "ingrese la descripcion: ";

    cin.getline(esp._descripcion,300);

    esp.setEstado(true);

    archivo.guardar(esp);
}

void Especialidades::Mostrar(){

    if (_estado == true){
        cout << "ID : " << _idEspecialidad << endl;
        cout << "Nombre : " << _nombre << endl;
        cout << "descripcion: " << _descripcion << endl;
        cout << "estado: " << _estado << endl << endl;
    }
}

void Especialidades::MostrarTodas(){

    ArchivoEspecialidades archivo;
    Especialidades esp;
    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg;i++){

        esp = archivo.leer(i);
        if(esp.getEstado() == true){

            cout <<  "ID : " << esp.getIdEspecialidad() << endl;
            cout <<  "Nombre : " << esp.getNombre() << endl;
            cout <<  "descripcion: " << esp.getDescripcion() << endl;
            cout <<  "estado: " <<esp.getEstado() << endl;
        }
    }
}

int Especialidades::Eleccion(){
    cout << "Ingrese su especialidad: " << endl;
    Especialidades esp;

        cout << "1- Clinico" <<endl;
        cout << "2- Oftalmologo" << endl;
        cout << "3- Odontologo" << endl;
        cout << "4- Pediatra" << endl;
        cout << "5- Traumatologo " << endl;
        cout << "6- Dermatologo" << endl;
        cout << "7- Cardiologo" << endl;
        do
        {
            cin >>_idEspecialidad;
            if (_idEspecialidad < 1 || _idEspecialidad  > 7)
            {
                cout << "Error al elegir la especialidad, vuelva a seleccionar." << endl;
            }
        }
        while (_idEspecialidad < 1 || _idEspecialidad  > 7 );

return _idEspecialidad;
}

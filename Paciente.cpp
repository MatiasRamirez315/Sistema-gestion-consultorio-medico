#include "Paciente.h"
#include "ArchivoPaciente.h"
#include "Persona.h"
#include "Fecha.h"
#include <string>
#include <cstring>

using namespace std;

void Paciente::setIdPaciente(int ID){
    _idPaciente = ID;
}

void Paciente::setTelefono(const char* tel){

       strcpy(_telefono, tel);

}

void Paciente::setEmail(const char* email){

 strcpy(_email, email);

}

void Paciente::setGenero(char g){
    _genero = g;
}

void Paciente::setIdObraSocial(int id){
    _idObraSocial = id;
}

void Paciente::setFechaNacimiento(Fecha fechaNac){
    _fechaNacimiento = fechaNac;
}

void Paciente::setEstado(bool estado){
    _estado = estado;
}

int Paciente::getIdPaciente(){
    return _idPaciente;
}

const char* Paciente::getTelefono(){
    return _telefono;
}

const char* Paciente::getEmail(){
    return _email;
}

char Paciente::getGenero(){
    return _genero;
}

int Paciente::getIdObraSocial(){
    return _idObraSocial;
}

Fecha Paciente::getFechaNac(){
    return _fechaNacimiento;
}

bool Paciente::getEstado(){
    return _estado;
}

void Paciente::CargarPaciente(){
    bool op = false;
    Paciente paciente;
    ArchivoPaciente archivo;
    int id;

    do{
    paciente.Persona::Cargar();

    id = archivo.getNuevoId();
    paciente.setIdPaciente(id);
    cout << "el ID del paciente es: " << id << endl;

    cout << "Ingrese el telefono: ";
    cin >> paciente._telefono;

    cout << "Ingrese el email: ";
    cin >> paciente._email;

    cout << "Ingrese el genero (F o M): ";
    do{
            cin >> paciente._genero;
            if (paciente.getGenero() != 'F'  || paciente.getGenero() != 'M' || paciente.getGenero() != 'f'  || paciente.getGenero() != 'm'){
                cout << "ingrese un genero valido" << endl;
            }
    }while (paciente.getGenero() == 'F'  || paciente.getGenero() == 'M' || paciente.getGenero() == 'f'  || paciente.getGenero() == 'm' );


    cout << "Ingrese el ID de la obra social: ";
    cin >> paciente._idObraSocial;

    paciente._fechaNacimiento.CargarFecha();

    cout << "Desea confirmar sus datos? 1-Si 0-No: ";
    cin >> op;
    if(op == false){cin.ignore();};
    }while (op== false);

    paciente.setEstado(true);

    if (archivo.guardar(paciente)){
            cout << "exito al guardar... " << endl;
    }
    else {
            cout << "no se pudo guardar el paciente..." << endl;
    }

}

void Paciente::MostrarPaciente(){
    Persona::Mostrar();
    cout << "ID del paciente :"  << _idPaciente << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Genero: " << _genero<< endl;
    cout << "ID de la obra social: " << _idObraSocial<< endl;
    cout << "Fecha de nacimiento: " << _fechaNacimiento.toString()<< endl;
    cout << "Estado: " << _estado<< endl;
}

void Paciente::MostrarTodos(){
    ArchivoPaciente archivo;
    Paciente paciente;
    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){
        paciente = archivo.leer(i);
    if(paciente.getEstado() == true){
        paciente.Persona::Mostrar();
        cout << "ID del paciente:"  << paciente.getIdPaciente() << endl;
        cout << "Telefono: " << paciente.getTelefono() << endl ;
        cout << "Email: " << paciente.getEmail() << endl;
        cout << "Genero: " << paciente.getGenero() << endl;
        cout << "Fecha de nacimiento: " << paciente.getFechaNac().toString() << endl;
        cout << "Estado: " << paciente.getEstado() << endl << endl;
        }
    }
}


void Paciente::Eliminar(){
    ArchivoPaciente archivo;
    Paciente paciente;
    int id;
    int pos;
    cout << "Ingrese el ID del paciente que desea eliminar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);

        if(pos == -1)
    {
        cout << "Paciente no encontrado..." << endl;
        return;
    }

    paciente = archivo.leer(pos);

    paciente.setEstado(false);

    if (archivo.Modificar (paciente,pos)){

        cout << "Paciente eliminado con exito..." << endl;
    }
    else{
        cout << "Error al eliminar paciente..." << endl;
    }
}

void Paciente::Modificacion(){


    ArchivoPaciente archivo;
    Paciente paciente;
    int id;
    int pos;

    cout << "ingrese el ID del medico que quiere modificar: ";
    cin >> id;

    pos = archivo.BuscarPosXID(id);

        if(pos == -1)
    {
        cout << "Paciente no encontrado.." << endl;
        return;
    }
    else{

        paciente = archivo.leer(pos);

        cout << "medico hallado: " << endl;
        paciente.Mostrar();


        paciente.cargarModificado();

        if (archivo.Modificar (paciente,pos)){

            cout << "paciente modificado con exito.." << endl;
        }
        else{
            cout << "error al modificar el paciente.." << endl;
        }

    }


}

void Paciente::cargarModificado(){
        cout << "----------------------------" << endl;
        cout << "ingrese el nuevo paciente: " << endl;

bool op = false;
    Paciente paciente;
    do{
    Persona::Cargar();

    cout << "Ingrese el telefono: ";
    cin >> _telefono;

    cout << "Ingrese el email: ";
    cin >> _email;

    cout << "Ingrese el genero (F o M): ";
    cin >> _genero;

    cout << "Ingrese el ID de la obra social: ";
    cin >> _idObraSocial;

    _fechaNacimiento.CargarFecha();

    cout << "Desea confirmar sus datos? 1-Si 0-No: ";
    cin >> op;
    if(op == false){
            cin.ignore();
    }
    }while (op== false);

    setEstado(true);
}

#include "Paciente.h"
#include "ArchivoPaciente.h"
#include "ArchivoObraSociales.h"
#include "ObraSociales.h"
#include "Validaciones.h"
#include "Persona.h"
#include "Fecha.h"
#include <string>
#include <cstring>
#include <cctype>
#include <limits>

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
    ObraSociales OS;
    int id;
    bool ok = false;
    string genero;

    do{
    paciente.Persona::Cargar();

    id = archivo.getNuevoId();
    paciente.setIdPaciente(id);
    cout << "el ID del paciente es: " << id << endl;

    do{
        cout << "ingrese la fecha de nacimiento: " << endl;
        paciente._fechaNacimiento.CargarFecha();
        ok = FechaMenorIgualActual(paciente._fechaNacimiento);
            if (FechaMenorIgualActual(paciente._fechaNacimiento) == false){
                cout << "Fecha invalida, ingrese otra.. " << endl;
            }
    }while (ok == false);

    cout << "Ingrese el telefono: ";
    cin.getline(paciente._telefono,15);

    cout << "Ingrese el email: ";
    cin.getline(paciente._email,70);



    cout << "Ingrese el genero (F o M): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(true) {
        getline(cin, genero);

        if (genero.length() != 1) {
            cout << "Debe ingresar una sola letra..." << endl;
            continue;
        }

        char letra = toupper(genero[0]);

        if (letra == 'F' || letra == 'M') {
            paciente._genero = letra;
            break;
        }

        cout << "Ingrese un genero valido (F o M): ";

    }

    OS.MostrarNombreID();
    ArchivoObraSociales archivoOS;
    int cantOS = archivoOS.contarRegistros();

    bool existe;

    do {
        existe = false;

        paciente._idObraSocial = obtenerEnteroValidado(
            "Ingrese el ID de la obra social (0 = Sin obra social): "
        );

        if (paciente._idObraSocial == 0) {
            existe = true;
        } else {
            for (int i = 0; i < cantOS; i++) {
                OS = archivoOS.leer(i);

                if (paciente._idObraSocial == OS.getIdObraSocial()) {
                    existe = true;
                    break;
                }
            }
        }

        if (existe == false) {
            cout << "La obra social ingresada no existe." << endl;
        }

    } while (existe == false);



    cout << "Desea confirmar sus datos? 1-Si 0-No: ";
    op = obtenerBooleanoValidado(" ");

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
    id = obtenerEnteroValidado("");;

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
    id = obtenerEnteroValidado("");

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
    ObraSociales OS;
    bool ok;
    do{
    Persona::Cargar();
    string genero;

    do{
        cout << "ingrese la fecha de nacimiento: " << endl;
        paciente._fechaNacimiento.CargarFecha();
        ok = FechaMenorIgualActual(paciente._fechaNacimiento);
            if (FechaMenorIgualActual(paciente._fechaNacimiento) == false){
                cout << "Fecha invalida, ingrese otra.. " << endl;
            }
    }while (ok == false);

    cout << "Ingrese el telefono: ";
    cin >> _telefono;

    cout << "Ingrese el email: ";
    cin >> _email;

    cout << "Ingrese el genero (F o M): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(true) {
        getline(cin, genero);

        if (genero.length() != 1) {
            cout << "Debe ingresar una sola letra..." << endl;
            continue;
        }

        char letra = toupper(genero[0]);

        if (letra == 'F' || letra == 'M') {
            paciente._genero = letra;
            break;
        }

        cout << "Ingrese un genero valido (F o M): ";

    }

    OS.MostrarNombreID();
    ArchivoObraSociales archivoOS;
    int cantOS = archivoOS.contarRegistros();

    bool existe;

    do {
        existe = false;

        paciente._idObraSocial = obtenerEnteroValidado(
            "Ingrese el ID de la obra social (0 = Sin obra social): "
        );

        if (paciente._idObraSocial == 0) {
            existe = true;
        } else {
            for (int i = 0; i < cantOS; i++) {
                OS = archivoOS.leer(i);

                if (paciente._idObraSocial == OS.getIdObraSocial()) {
                    existe = true;
                    break;
                }
            }
        }

        if (existe == false) {
            cout << "La obra social ingresada no existe." << endl;
        }

    } while (existe == false);

    cout << "Desea confirmar sus datos? 1-Si 0-No: ";
    op = obtenerBooleanoValidado(" ");

    }while (op== false);

    setEstado(true);
}

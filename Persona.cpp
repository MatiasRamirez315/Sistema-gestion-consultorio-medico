#include "Persona.h"
#include "Validaciones.h"
#include <cstring>

using namespace std;

void Persona::setNombre (const char* nombre){
strcpy(_nombre, nombre);

}

void Persona::setApellido(const char * apellido){
strcpy(_apellido, apellido);

}

void Persona::setDNI(int dni){
    _dni = dni;
}

const char*  Persona::getNombre(){
    return _nombre;
}

const char* Persona::getApellido(){
    return _apellido;
}

int Persona::getDNI(){
    return _dni;
}

void Persona::Cargar(){
    bool ok = false;
    do{

    cout << "Ingrese el nombre : ";

    cin.getline(_nombre,50);
    if (esPalabraValida(_nombre)){
            ok = true;
        }
        else{
            cout << "ingrese un nombre valido.. " << endl << endl;
        }
    }while (ok == false);

    ok = false;
    do{
    cout << "Ingrese el apellido: ";
    cin.getline(_apellido,50);
        if (esPalabraValida(_apellido)){
            ok = true;
        }
        else{
            cout << "ingrese un apellido valido.. " << endl << endl;
        }
    }while (ok ==false);

    cout << "ingrese el DNI: ";
    _dni = obtenerEnteroValidado("");


}

void Persona::Mostrar(){
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _dni << endl;
}

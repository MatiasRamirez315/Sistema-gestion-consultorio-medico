#include "Consultorios.h"
#include "ArchivoConsultorios.h"
#include <iostream>

using namespace std;

void Consultorios::setIdConsultorio(int id){
_idConsultorio = id;
}

void Consultorios::setFechaOcupado (Fecha f){
_fechaOcupado = f;
}

void Consultorios::setHoraOcupado (Hora h){
_horaOcupado = h;
}

void Consultorios::setEstado(bool e){
_estado = e;
}

int Consultorios::getIDConsultorio () {
    return _idConsultorio;
}

Fecha Consultorios::getFechaOcupado(){
return _fechaOcupado;
}

Hora Consultorios::getHoraOcupado(){
return _horaOcupado;
}

bool Consultorios::getEstado(){
    return _estado;
    }

void Consultorios::Cargar(){
ArchivoConsultorios archivo;
Consultorios consultorio;
int id = archivo.getNuevoId();
consultorio.setIdConsultorio(id) ;
consultorio._fechaOcupado;
consultorio._horaOcupado;

consultorio.setEstado(false);

if(archivo.guardar(consultorio)){
    cout << "Se agrego un nuevo consultorio.." << endl;
}
else {
    cout << "no se pudo agregar el consultorio nuevo" << endl;
}

}

void Consultorios::Mostrar(){
cout << "el consultorio #" << _idConsultorio << " se encuentra ";
if (getEstado() == true){
     cout << "ocupado ";
    }
    else{
        cout << "desocupado ";
    }
    cout << "en el dia " << _fechaOcupado.toString() << " a las " << _horaOcupado.toString() << endl;
}


void Consultorios::MostrarTodos(){
    ArchivoConsultorios archivo;
    Consultorios cons;
    int cantReg = archivo.contarRegistros();

    for (int i=0;i<cantReg ; i++){
        cons = archivo.leer(i);
        cout << "el consultorio #" << cons._idConsultorio  << " se encuentra ";
        if (getEstado() == true){
                cout << "ocupado " ;
            }
        else{
                cout << "desocupado " ;
            }
            cout << "en el dia " << _fechaOcupado.toString() << " a las " << _horaOcupado.toString() << endl;
        }
}


#include <string>
#include <cstring>
#include "ArchivoTurnos.h"

using namespace std;

ArchivoTurnos:: ArchivoTurnos() {strcpy (_nombre,"Turnos.dat");}

bool ArchivoTurnos::guardar(Turnos obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Turnos), 1, p);
  fclose(p);
  return pudoEscribir;
}
Turnos ArchivoTurnos::leer(int pos){

  Turnos aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Turnos), SEEK_SET);
  fread(&aux, sizeof(Turnos), 1, p);
  fclose(p);
  return aux;

}
int ArchivoTurnos::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Turnos);
    fclose(p);
return cantidad;
}

int ArchivoTurnos::BuscarPosXID(int id){

    Turnos aux;
    int pos=0;

    FILE *p=fopen(_nombre,"rb");
    if(p==NULL){
            return -1;
    }

    while(fread(&aux,sizeof(Turnos),1,p)){
        if(aux.getIdTurno()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

bool ArchivoTurnos::Modificar(Turnos turno,int pos){

    FILE *p=fopen(_nombre,"rb+");
    if(p==NULL)return false;

    fseek(p,pos*sizeof(Turnos),SEEK_SET);

    bool pudoModificar=fwrite(&turno,sizeof(Turnos),1,p);

    fclose(p);

    return pudoModificar;
}

int ArchivoTurnos::getNuevoId()
{
    return contarRegistros()+1;
}

// Busca si existe un turno activo asociado
// a una agenda determinada.
bool ArchivoTurnos::ExisteTurnoActivoPorAgenda(int idAgenda)
{
    Turnos turno;
    int cantidad;
    cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++)
    {
        turno = leer(i);
        /*
            La agenda se considera ocupada únicamente si:

            1. El turno usa ese ID de agenda.
            2. El turno está activo.

            Si el turno fue cancelado, su estado es false
            y la agenda vuelve a considerarse disponible.
        */
        if(turno.getIdAgendaMedico()==idAgenda&&turno.getEstado())
        {
            return true;
        }
    }
    return false;
}

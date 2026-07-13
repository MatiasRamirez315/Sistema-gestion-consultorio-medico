#include <string>
#include <cstring>
#include "ArchivoTurnos.h"
#include <cstring>

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


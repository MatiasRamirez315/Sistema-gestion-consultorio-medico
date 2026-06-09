#include <string>
#include <cstring>
#include "ArchivoTurnos.h"
#include <cstring>

ArchivoTurnos::ArchivoTurnos(const char* nombre){
    strcpy(_nombre, nombre);
}

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

int ArchivoTurnos::getNuevoId()
{
    return contarRegistros()+1;
}


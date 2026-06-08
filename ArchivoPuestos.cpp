#include <string>
#include <cstring>
#include "ArchivoPuestos.h"

using namespace std;

ArchivoPuestos:: ArchivoPuestos( ){strcpy (_nombre,"Puestos.dat");}

bool ArchivoPuestos::guardar(Puestos obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Puestos), 1, p);
  fclose(p);
  return pudoEscribir;
}
Puestos ArchivoPuestos::leer(int pos){

  Puestos aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Puestos), SEEK_SET);
  fread(&aux, sizeof(Puestos), 1, p);
  fclose(p);
  return aux;

}
int ArchivoPuestos::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Puestos);
    fclose(p);
return cantidad;
}

int ArchivoPuestos::getNuevoId()
{
    return contarRegistros()+1;
}

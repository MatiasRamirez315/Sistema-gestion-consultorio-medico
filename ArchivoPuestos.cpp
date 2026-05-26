//Alumno: Matias Hernan Ramirez
#include "ArchivoPuestos.h"

bool ArchivoPuestos::guardar(Puestos obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Puestos), 1, p);
  fclose(p);
  return pudoEscribir;
};
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

};
int ArchivoPuestos::contarRegistros(){


 FILE *p = fopen(_nombre, "rb");

  if (p == NULL)
  {
    return 0;
 }
};

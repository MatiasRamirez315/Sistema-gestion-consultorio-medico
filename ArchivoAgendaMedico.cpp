#include "ArchivoAgendaMedico.h"

bool ArchivoAgendaMedicos::guardar(AgendaMedicos obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(AgendaMedicos), 1, p);
  fclose(p);
  return pudoEscribir;
};

AgendaMedicos ArchivoAgendaMedicos::leer(int pos){

  AgendaMedicos aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(AgendaMedicos), SEEK_SET);
  fread(&aux, sizeof(AgendaMedicos), 1, p);
  fclose(p);
  return aux;
};

int ArchivoAgendaMedicos::getCantRegistros(){

 FILE *p = fopen(_nombre, "rb");

  if (p == NULL)
  {
    return 0;
 }

 };

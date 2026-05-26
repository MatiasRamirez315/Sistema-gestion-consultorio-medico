#include "ArchivoPaciente.h"

bool ArchivoPaciente::guardar(Paciente obj){
  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Paciente), 1, p);
  fclose(p);
  return pudoEscribir;
};

Paciente ArchivoPaciente::leer(int pos){

  Paciente aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Paciente), SEEK_SET);
  fread(&aux, sizeof(Paciente), 1, p);
  fclose(p);
  return aux;

};
int ArchivoPaciente::contarRegistros(){

 FILE *p = fopen(_nombre, "rb");

  if (p == NULL)
  {
    return 0;
 }



};

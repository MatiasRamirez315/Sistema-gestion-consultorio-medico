#include "ArchivoEspecialidades.h"

bool ArchivoEspecialidades::guardar(Especialidades obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Especialidades), 1, p);
  fclose(p);
  return pudoEscribir;

}
Especialidades ArchivoEspecialidades::leer(int pos){
  Especialidades aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Especialidades), SEEK_SET);
  fread(&aux, sizeof(Especialidades), 1, p);
  fclose(p);
  return aux;

}
int ArchivoEspecialidades::contarRegistros(){

FILE *p = fopen(_nombre, "rb");

  if (p == NULL)
  {
    return 0;
 }
}

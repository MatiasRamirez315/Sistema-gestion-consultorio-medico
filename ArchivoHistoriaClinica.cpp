#include "ArchivoHistoriaClinica.h"

bool ArchivoHistoriaClinica::guardar(HistoriaClinica obj){


  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(HistoriaClinica), 1, p);
  fclose(p);
  return pudoEscribir;

}
HistoriaClinica ArchivoHistoriaClinica::leer(int pos){
 HistoriaClinica aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(HistoriaClinica), SEEK_SET);
  fread(&aux, sizeof(HistoriaClinica), 1, p);
  fclose(p);
  return aux;

}
int ArchivoHistoriaClinica::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(HistoriaClinica);
    fclose(p);
return cantidad;
}


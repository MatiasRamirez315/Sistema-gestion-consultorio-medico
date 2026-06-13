#include <string>
#include <cstring>
#include "ArchivoHistoriaClinica.h"

ArchivoHistoriaClinica:: ArchivoHistoriaClinica( ){
    strcpy (_nombre,"HistoriaClinica.dat");
    }

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

int ArchivoHistoriaClinica::getNuevoId()
{
    return contarRegistros()+1;
}

int ArchivoHistoriaClinica::BuscarPosXID(int id){

    //ArchivoHistoriaClinica archivo;
    HistoriaClinica aux;
    int pos=0;

    FILE *p=fopen(_nombre,"rb");
    if(p==NULL){
            return -1;
    }

    while(fread(&aux,sizeof(HistoriaClinica),1,p)){
        if(aux.getIdPaciente()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;

}



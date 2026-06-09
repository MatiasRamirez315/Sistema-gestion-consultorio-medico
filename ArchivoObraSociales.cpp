#include <string>
#include <cstring>
#include "ArchivoObraSociales.h"

ArchivoObraSociales::ArchivoObraSociales(){strcpy (_nombre,"ObrasSociales.dat");}

bool ArchivoObraSociales::guardar(ObraSociales obj){
  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(ObraSociales), 1, p);
  fclose(p);
  return pudoEscribir;


}
ObraSociales ArchivoObraSociales::leer(int pos){

  ObraSociales aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(ObraSociales), SEEK_SET);
  fread(&aux, sizeof(ObraSociales), 1, p);
  fclose(p);
  return aux;

}

int ArchivoObraSociales::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(ObraSociales);
    fclose(p);
return cantidad;
}

int ArchivoObraSociales::getNuevoId()
{
    return contarRegistros()+1;
}

int ArchivoObraSociales::BuscarPosXID(int id){

    ObraSociales aux;
    int pos=0;

    FILE *p=fopen(_nombre,"rb");
    if(p==NULL){
            return -1;
    }

    while(fread(&aux,sizeof(ObraSociales),1,p)){
        if(aux.getIdObraSocial()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

bool ArchivoObraSociales::Modificar(ObraSociales OS,int pos){

    FILE *p=fopen(_nombre,"rb+");
    if(p==NULL)return false;

    fseek(p,pos*sizeof(ObraSociales),SEEK_SET);

    bool pudoModificar=fwrite(&OS,sizeof(ObraSociales),1,p);

    fclose(p);

    return pudoModificar;
}


#include <cstring>
#include <cstdio>
#include "ArchivoConsultorios.h"

ArchivoConsultorios :: ArchivoConsultorios(){
strcpy (_nombre,"Consultorios.dat");
}

bool ArchivoConsultorios::guardar(Consultorios obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Consultorios), 1, p);
  fclose(p);
  return pudoEscribir;

}

Consultorios ArchivoConsultorios::leer(int pos){


  Consultorios aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Consultorios), SEEK_SET);
  fread(&aux, sizeof(Consultorios), 1, p);
  fclose(p);
  return aux;

}
int ArchivoConsultorios::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Consultorios);
    fclose(p);
return cantidad;
}

int ArchivoConsultorios::getNuevoId(){
    return contarRegistros()+1;
}


int ArchivoConsultorios::BuscarPosXID(int id){

    Consultorios aux;
    int pos=0;

    FILE *p=fopen(_nombre,"rb");
    if(p==NULL){
            return -1;
    }

    while(fread(&aux,sizeof(Consultorios),1,p)){
        if(aux.getIDConsultorio()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

bool ArchivoConsultorios::Modificar(Consultorios cons,int pos){

    FILE *p=fopen(_nombre,"rb+");
    if(p==NULL)return false;

    fseek(p,pos*sizeof(Consultorios),SEEK_SET);

    bool pudoModificar=fwrite(&cons,sizeof(Consultorios),1,p);

    fclose(p);

    return pudoModificar;
}

bool ArchivoConsultorios::Existe(int idConsultorio){
    Consultorios reg;
    ArchivoConsultorios archivo;

    int cant = contarRegistros();

    for (int i = 0; i < cant; i++){
        reg =archivo.leer(i);

        if (reg.getIDConsultorio() == idConsultorio && reg.getEstado() == false){

            return true;
        }
    }
    return false;
}

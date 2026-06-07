#include <string>
#include <cstring>
#include "ArchivoConsultorios.h"

using namespace std;

ArchivoConsultorios::ArchivoConsultorios(string nombreArchivo)
    :_nombre(nombreArchivo)
{
}

bool ArchivoConsultorios::guardar(Consultorios obj){

  FILE *p = fopen(_nombre.c_str(), "ab");

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
  FILE *p = fopen(_nombre.c_str(), "rb");
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
    FILE*p=fopen(_nombre.c_str(),"rb");
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

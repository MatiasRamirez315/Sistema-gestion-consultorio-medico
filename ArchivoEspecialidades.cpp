#include <string>
#include <cstring>
#include "ArchivoEspecialidades.h"

using namespace std;

ArchivoEspecialidades::ArchivoEspecialidades(string nombreArchivo)
    :_nombre(nombreArchivo)
{
}


bool ArchivoEspecialidades::guardar(Especialidades obj){

  FILE *p = fopen(_nombre.c_str(), "ab");

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
  FILE *p = fopen(_nombre.c_str(), "rb");
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
    FILE*p=fopen(_nombre.c_str(),"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Especialidades);
    fclose(p);
return cantidad;
}

int ArchivoEspecialidades::getNuevoId()
{
    return contarRegistros()+1;
}

#include <string>
#include <cstring>
#include "ArchivoAgendaMedico.h"

using namespace std;

ArchivoAgendaMedicos::ArchivoAgendaMedicos(string nombreArchivo)
    :_nombre(nombreArchivo)
{
}

bool ArchivoAgendaMedicos::guardar(AgendaMedicos obj){

  FILE *p = fopen(_nombre.c_str(), "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(AgendaMedicos), 1, p);
  fclose(p);
  return pudoEscribir;
}

AgendaMedicos ArchivoAgendaMedicos::leer(int pos){

  AgendaMedicos aux;
  FILE *p = fopen(_nombre.c_str(), "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(AgendaMedicos), SEEK_SET);
  fread(&aux, sizeof(AgendaMedicos), 1, p);
  fclose(p);
  return aux;
}

int ArchivoAgendaMedicos::getCantRegistros(){
    FILE*p=fopen(_nombre.c_str(),"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(AgendaMedicos);
    fclose(p);
return cantidad;
}

int ArchivoAgendaMedicos::getNuevoId()
{
    return getCantRegistros()+1;
}


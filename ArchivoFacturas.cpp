#include <string>
#include <cstring>
#include "ArchivoFacturas.h"

using namespace std;

ArchivoFacturas::ArchivoFacturas(string nombreArchivo)
    :_nombre(nombreArchivo)
{
}

bool ArchivoFacturas::guardar(Facturas obj){

 FILE *p = fopen(_nombre.c_str(), "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Facturas), 1, p);
  fclose(p);
  return pudoEscribir;
}
Facturas ArchivoFacturas::leer(int pos){

  Facturas aux;
  FILE *p = fopen(_nombre.c_str(), "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Facturas), SEEK_SET);
  fread(&aux, sizeof(Facturas), 1, p);
  fclose(p);
  return aux;

}
int ArchivoFacturas::contarRegistros(){
    FILE*p=fopen(_nombre.c_str(),"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Facturas);
    fclose(p);
return cantidad;
}

int ArchivoFacturas::getNuevoId()
{
    return contarRegistros()+1;
}



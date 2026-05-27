#include "ArchivoFacturas.h"

bool ArchivoFacturas::guardar(Facturas obj){

 FILE *p = fopen(_nombre, "ab");

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
  FILE *p = fopen(_nombre, "rb");
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

 FILE *p = fopen(_nombre, "rb");

  if (p == NULL)
  {
    return 0;
 }


}

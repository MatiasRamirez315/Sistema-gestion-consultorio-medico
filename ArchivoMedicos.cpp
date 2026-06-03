#include "ArchivoMedicos.h"

ArchivoMedicos::ArchivoMedicos(){
    strcpy(_nombre,"Medicos.dat");
}


bool ArchivoMedicos::guardar(Medico obj){

  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Medico), 1, p);
  fclose(p);
  if (pudoEscribir == 1){
    cout << "Exito al guardar..." << endl;
  }
  else{
    cout << "Error al guardar..." << endl;
  }
  return pudoEscribir;
}


Medico ArchivoMedicos::leer(int pos){

  Medico aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Medico), SEEK_SET);
  fread(&aux, sizeof(Medico), 1, p);
  fclose(p);
  return aux;
}
int ArchivoMedicos::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Medico);
    fclose(p);
return cantidad;
}


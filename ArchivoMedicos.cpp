#include <string>
#include <cstring>
#include "ArchivoMedicos.h"

ArchivoMedicos::ArchivoMedicos(){strcpy (_nombre,"Medicos.dat");}

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
int ArchivoMedicos::BuscarPosXID(int id){

    Medico aux;
    int pos = 0;

    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        return -1;
    }

    while (fread(&aux, sizeof(Medico), 1, p))
    {
        if (aux.getIdMedico() == id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
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

bool ArchivoMedicos::Modificar (Medico medico, int pos){

  FILE *p = fopen(_nombre, "rb+");

  if (p == NULL)
  {
    return false;
  }

    fseek(p, pos * sizeof(Medico), SEEK_SET);

  bool pudoModificar = fwrite(&medico, sizeof(Medico), 1, p);
  fclose(p);

  return pudoModificar;


}

int ArchivoMedicos::getNuevoId()
{
    return contarRegistros()+1;
}


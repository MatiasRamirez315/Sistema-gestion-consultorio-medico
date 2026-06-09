#include <string>
#include <cstring>
#include "ArchivoPaciente.h"

ArchivoPaciente::ArchivoPaciente(){strcpy (_nombre,"Pacientes.dat");}

bool ArchivoPaciente::guardar(Paciente obj){
  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&obj, sizeof(Paciente), 1, p);
  fclose(p);
  return pudoEscribir;
}

Paciente ArchivoPaciente::leer(int pos){

  Paciente aux;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
  {
    return aux;
  }

  fseek(p, pos * sizeof(Paciente), SEEK_SET);
  fread(&aux, sizeof(Paciente), 1, p);
  fclose(p);
  return aux;

}

int ArchivoPaciente::BuscarPosXID(int id){
    Paciente aux;
    int pos = 0;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        return -1;
    }

    while (fread(&aux, sizeof(Paciente), 1, p) ) {
    if (aux.getIdPaciente() == id){
            fclose(p);
            return pos;
        }
        pos++;
    }
}

int ArchivoPaciente::contarRegistros(){
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
return 0;
    }

    fseek(p,0,SEEK_END);
    int cantidad=ftell(p)/sizeof(Paciente);
    fclose(p);
return cantidad;
}

bool ArchivoPaciente::Modificar (Paciente paciente, int pos){

    FILE *p = fopen(_nombre, "rb+");

    if (p == NULL){
        return false;
    }

    fseek(p, pos * sizeof(Paciente), SEEK_SET);

    bool pudoModificar = fwrite(&paciente, sizeof(Paciente), 1, p);
    fclose(p);

    return pudoModificar;
}

int ArchivoPaciente::getNuevoId()
{
    return contarRegistros()+1;
}


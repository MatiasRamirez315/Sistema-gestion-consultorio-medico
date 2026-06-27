#include <string>
#include <cstring>
#include "ArchivoAgendaMedico.h"

using namespace std;

ArchivoAgendaMedicos::ArchivoAgendaMedicos(){
    strcpy (_nombre,"AgendaMedicos.dat");
    }

bool ArchivoAgendaMedicos::guardar(AgendaMedicos obj){

  FILE *p = fopen(_nombre, "ab");

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
  FILE *p = fopen(_nombre, "rb");
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
    FILE*p=fopen(_nombre,"rb");
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

bool ArchivoAgendaMedicos::EstaOcupado(
    int idConsultorio,
    Fecha fecha,
    Hora hora)
{
    AgendaMedicos agenda;

    int cantReg = getCantRegistros();

    for(int i=0; i<cantReg; i++){

        agenda = leer(i);

        if(agenda.getIdConsultorio() == idConsultorio &&
           agenda.getFecha() == fecha &&
           agenda.getHorario() == hora)
        {
            return true;
        }
    }

    return false;
}

int ArchivoAgendaMedicos::BuscarPosXID(int id){

    AgendaMedicos aux;
    int pos=0;

    FILE *p=fopen(_nombre,"rb");
    if(p==NULL){
            return -1;
    }

    while(fread(&aux,sizeof(AgendaMedicos),1,p)){
        if(aux.getIdAgendaMedico()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

#include "Usuario.h"
#include <cstring>

void Usuario::setMail(const char* mail){
strcpy(_mail,mail);

}
void Usuario::setContrasenia (const char * contrasenia){
strcpy(_contrasenia,contrasenia);
}
void Usuario::setRol (bool rol){
_rol = rol;
}
void Usuario::setEstado (bool estado){
_estado = estado;
}

const char * Usuario::getMail(){
    return _mail;
}
const char* Usuario::getConstrasenia(){
    return _contrasenia;
};
bool Usuario::getRol(){
    return _rol;
}
bool Usuario::getEstado(){
    return _estado;
}

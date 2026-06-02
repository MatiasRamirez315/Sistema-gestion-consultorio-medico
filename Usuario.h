#pragma once

class Usuario{
private:
    char  _mail[50];
    char _contrasenia[8];
    bool _rol;
    bool _estado;

public:
    void setMail(const char* mail);
    void setContrasenia (const char * contrasenia);
    void setRol (bool rol);
    void setEstado (bool estado);

    const char * getMail();
    const char* getConstrasenia();
    bool getRol();
    bool getEstado();

};

#pragma once
#include <string>
#include "Fecha.h"

bool esPalabraValida(const char* palabra);

bool esEnteroValido(const std::string& input);

int obtenerEnteroValidado(const std::string& mensaje);

bool obtenerBooleanoValidado(const std::string& mensaje);

bool esBooleanoValido(const std::string& input);

int obtenerEnteroPositivo(const std::string& mensaje);

bool FechaMenorIgualActual (Fecha fecha);

bool FechaMayorIgualActual (Fecha fecha);

bool esEnteroPositivoValido(const std::string& input) ;

bool FechaMenorIgualActual (Fecha fecha);

int obtenerHoraValidada();

int obtenerMinutosValidados();

bool esFloatValido(const std::string& input);

float obtenerFloatValidado(const std::string& mensaje);



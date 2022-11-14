#pragma once
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
using namespace std;

//Estructuras
typedef struct {
    string id;
    string nombre;
    string apellido;
    string telefono;
    string especialidad;
    bool activo;
} t_medico;

typedef struct {
    string dni;
    string nombre;
    string apellido;
    string sexo;
    tm nacimiento;  // DD/MM/YY
    string estado;
    string id_os;
    string telefono;
    string celular;
    string direccion;
    string mail;
} t_paciente;

typedef struct {
    string id;
    string nombre;  //podria ser un enum
} t_obra_social;

typedef struct {
    string dni_paciente;
    tm fecha_solicitado;
    tm fecha_turno;   // DD/MM/YY
    bool presento;
    string id_medico;
} t_consulta;


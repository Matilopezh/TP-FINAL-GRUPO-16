#pragma once
#include "general.h"

void agregar_paciente(t_paciente*& Lista, t_paciente Nuevo, int* tamactual);
void agregar_medico(t_medico*& Lista, t_medico Nuevo, int* tamactual);
void agregar_OS(t_obra_social*& Lista, t_obra_social Nuevo, int* tamactual);
void agregar_consulta(t_consulta*& Lista, t_consulta Nuevo, int* tamactual);

void FiltrarPacienteRep(t_paciente*& Lista, int* tamLista);
void FiltrarMedicoRep(t_medico*& Lista, int* tamLista);
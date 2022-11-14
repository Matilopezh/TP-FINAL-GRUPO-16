#include "funciones.h"
#include <string>
using namespace std;


void agregar_paciente(t_paciente*& Lista, t_paciente Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;  //agranda 1 en tamaño de la lista
	int i = 0;
	t_paciente* aux = new t_paciente[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];        //copia todo lo de la lista vieja a la nueva
		i++;
	}
	aux[i] = Nuevo;               //agrega el elemento a la ultima pos de la nueva lista

	delete[] Lista;
	Lista = aux;                  //reapunta el puntero a la nueva lista

	return;
}
void agregar_medico(t_medico*&, int* tamPLista, t_medico Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_medico* aux = new t_medico[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}
void agregar_OS(t_obra_social*& Lista, t_obra_social Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_obra_social* aux = new t_obra_social[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}
void agregar_consulta(t_consulta*& Lista, t_consulta Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_consulta* aux = new t_consulta[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}

void FiltrarPacienteRep(t_paciente*& Lista, int* tamP) {
	int cont = 0, i, j;
	for (i = 0; i < *tamP - 1; i++) {
		for (j = i; j < *tamP - 1; j++) {
			if (Lista[i].dni == Lista[j + 1].dni) {  //recorro la lista marcando los repetidos
				Lista[j + 1].dni = "repetido";
				cont++;
			}
		}
	}
	t_paciente paciente_aux;
	for (i = 0; i < *tamP - 1; i++) {
		if (Lista[i].dni == "repetido") {
			for (j = i; j < *tamP - 1; j++) {      //ordeno los repetidos al final 
				paciente_aux = Lista[j];
				Lista[j] = Lista[j + 1];
				Lista[j + 1] = paciente_aux;
			}
		}

	}
	*tamP -= cont; //saco de la lista a los repetidos que me quedaron al final 
	return;
}
void FiltrarMedicoRep(t_medico*& Lista, int* tamM) {
	int cont = 0, i, j;
	for (i = 0; i < *tamM - 1; i++) {
		for (j = i; j < *tamM - 1; j++) {
			if (Lista[i].dni == Lista[j + 1].dni) {  //recorro la lista marcando los repetidos
				Lista[j + 1].dni = "repetido";
				cont++;
			}
		}
	}
	t_paciente paciente_aux;
	for (i = 0; i < *tamM - 1; i++) {
		if (Lista[i].dni == "repetido") {
			for (j = i; j < *tamM - 1; j++) {      //ordeno los repetidos al final 
				paciente_aux = Lista[j];
				Lista[j] = Lista[j + 1];
				Lista[j + 1] = paciente_aux;
			}
		}

	}
	*tamM -= cont; //saco de la lista a los repetidos que me quedaron al final 
	return;
}
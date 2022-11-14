#include <iostream>

#include "funciones.h"
#include "funciones.cpp"



int main() {

    t_paciente* Pacientes = new t_paciente[0];
    t_medico* Medicos = new t_medico[0];
    t_consulta* Consultas = new t_consulta[0];
    t_obra_social* ObrasS = new t_obra_social[0];

    int* tamP = 0;
    int* tamM = 0;
    int* tamC = 0;
    int* tamOS = 0;  //cantidades en las listas 

    // SE LLENAN LAS LISTAS CON LA INFO DE LOS ARCHIVOS 

    // Pacientes = Pacientes.csv + Contactos.csv
    fstream arch1, arch2; //punteros a archivos que vamos a usar y rotar para llenar las listas

    arch1.open("IRI_Pacientes.csv", ios::in); //abrimos los archivos para pegarlos en las listas de las diferentes estructuras
    arch2.open("IRI_Contactos.csv", ios::in);

    if (!(arch1.is_open() && arch2.is_open())) {
        cout << "ERROR PARA ABRIR ARCHIVOS" << endl;  // si hay error abriendo los archivos concluye el programa
        return -1;
    }

    t_paciente paciente_aux;
    char coma = ',';
    string dni_aux;
    string H_paciente[11], dummy; //guardamos los headers de cada archivo --> como unimos el de pacientes con contactos se repite el id/dni de la persona --> dummy
    arch1 >> H_paciente[0] >> coma >> H_paciente[1] >> coma >> H_paciente[2] >> coma >> H_paciente[3] >> coma >> H_paciente[4] >> coma >> H_paciente[5] >> coma >> H_paciente[6];
    arch2 >> dummy >> coma >> H_paciente[7] >> coma >> H_paciente[8] >> coma >> H_paciente[9] >> coma >> H_paciente[10];
    while (arch1) {
        arch1 >> paciente_aux.dni >> coma >> paciente_aux.nombre >> coma >> paciente_aux.apellido >> coma >> paciente_aux.sexo >> coma >> paciente_aux.nacimiento >> coma >> paciente_aux.estado >> coma >> paciente_aux.id_os;
        while (arch2) {
            arch2 >> dni_aux;
            if (dni_aux == paciente_aux.dni)     //buscamos el contacto del paciente
                arch2 >> coma >> paciente_aux.telefono >> coma >> paciente_aux.apellido >> coma >> paciente_aux.direccion >> coma >> paciente_aux.mail;
        }
        agregar_paciente(Pacientes, paciente_aux, tamP);  //agregamos el paciente
    }
    arch1.close();
    arch2.close();

    arch1.open("IRI_ObraSocial.csv", ios::in);
    arch2.open("IRI_Medicos.csv", ios::in);
    if (!(arch1.is_open() && arch2.is_open())) {
        cout << "ERROR PARA ABRIR ARCHIVOS" << endl;
        return -1;
    }
    t_obra_social obsc_aux;
    t_medico medico_aux;
    string H_medico[6];
    string H_obraS[2];
    arch1 >> H_obraS[0] >> coma >> H_obraS[1];
    arch2 >> H_medico[0] >> coma >> H_medico[1] >> coma >> H_medico[2] >> coma >> H_medico[3] >> coma >> H_medico[4] >> coma >> H_medico[5];
    while (arch1) {
        arch1 >> obsc_aux.id >> coma >> obsc_aux.nombre;
        agregar_OS(ObrasS, obsc_aux, tamOS);
    }
    while (arch2) {
        arch2 >> medico_aux.id >> coma >> medico_aux.nombre >> coma >> medico_aux.apellido >> coma >> medico_aux.telefono >> coma >> medico_aux.especialidad >> coma >> medico_aux.activo;
        agregar_medico(Medicos, medico_aux, tamM);
    }
    arch1.close();
    arch2.close();

    arch1.open("IRI_Consultas.csv", ios::in);
    if (!(arch1.is_open())) {
        cout << "ERROR PARA ABRIR ARCHIVOS" << endl;
        return -1;
    }
    t_consulta consulta_aux;
    string H_consulta[5];
    arch1 >> H_consulta[0] >> coma >> H_consulta[1] >> coma >> H_consulta[2] >> coma >> H_consulta[3] >> coma >> H_consulta[4];
    while (arch1) {
        arch1 >> consulta_aux.dni_paciente >> coma >> consulta_aux.fecha_solicitado >> coma >> consulta_aux.fecha_turno >> coma >> consulta_aux.presento >> coma >> consulta_aux.id_medico;
        agregar_consulta(Consultas, consulta_aux, tamC);
    }
    arch1.close();

    // SE FILTRAN LOS MEDICOS Y PACIENTES REPETIDOS
    FiltrarMedicoRep(Medicos, tamM);
    FiltrarPacienteRep(Pacientes, tamP);


    //---------CODIGO----------//


    delete[] Pacientes;
    delete[] Medicos;
    delete[] ObrasS;
    delete[] Consultas;
    return EXIT_SUCCESS;
}
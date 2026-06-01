#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <time.h>
#include <locale.h> 

#define MAX_SIZE 5
#define MAXC 8

typedef struct {
    char name[50];
    int idade;
    int gravidade;
    int tipo_atendimento;
    
    time_t timestamp;
    time_t atendimento; //para mostrar o horario que o paciente foi atendido
    time_t transferencia; //mostar o horario de transferencia do paciente
} Paciente;

void cadastrarPaciente();
void atenderPaciente();
void mostrarPaciente();
void transferirPaciente();
void relatorio();

#endif
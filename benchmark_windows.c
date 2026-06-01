#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hospital.h"

extern Paciente pilha[MAX_SIZE];
extern int topo;

extern Paciente fila[MAX_SIZE];
extern int inicio, fim;

extern Paciente circ[MAXC];
extern int ic, fc, total;

double medirTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

Paciente gerarPaciente(int id, int gravidade) {
    Paciente p;

    snprintf(p.name, sizeof(p.name), "Paciente_%d", id);

    p.idade = (id % 100) + 1;
    p.gravidade = gravidade;
    p.tipo_atendimento = 0;

    return p;
}

void testeEmergencia(int n) {
    topo = -1;

    clock_t inicioTempo = clock();

    for (int i = 0; i < n; i++) {
        Paciente p = gerarPaciente(i, 5);

        if (topo < MAX_SIZE - 1)
            pilha[++topo] = p;
    }

    clock_t fimTempo = clock();

    double tempo = medirTempo(inicioTempo, fimTempo);

    printf("\n=== TESTE EMERGENCIA ===\n");
    printf("Operacoes: %d\n", n);
    printf("Tempo: %.6f s\n", tempo);
    if (tempo > 0)
        printf("Ops/s: %.2f\n", n / tempo);
}

void testeConsulta(int n) {
    inicio = 0;
    fim = 0;

    clock_t inicioTempo = clock();

    for (int i = 0; i < n; i++) {
        Paciente p = gerarPaciente(i, 2);

        if (fim < MAX_SIZE)
            fila[fim++] = p;
    }

    clock_t fimTempo = clock();

    double tempo = medirTempo(inicioTempo, fimTempo);

    printf("\n=== TESTE CONSULTA ===\n");
    printf("Operacoes: %d\n", n);
    printf("Tempo: %.6f s\n", tempo);
    if (tempo > 0)
        printf("Ops/s: %.2f\n", n / tempo);
}

void testeExames(int n) {
    ic = 0;
    fc = 0;
    total = 0;

    clock_t inicioTempo = clock();

    for (int i = 0; i < n; i++) {
        Paciente p = gerarPaciente(i, 1);

        if (total == MAXC) {
            ic = (ic + 1) % MAXC;
            total--;
        }

        circ[fc] = p;
        fc = (fc + 1) % MAXC;
        total++;
    }

    clock_t fimTempo = clock();

    double tempo = medirTempo(inicioTempo, fimTempo);

    printf("\n=== TESTE EXAMES ===\n");
    printf("Operacoes: %d\n", n);
    printf("Tempo: %.6f s\n", tempo);
    if (tempo > 0)
        printf("Ops/s: %.2f\n", n / tempo);
}

int main() {
    printf("===================================\n");
    printf("BENCHMARK - SISTEMA HOSPITALAR\n");
    printf("===================================\n");

    testeEmergencia(1000000);
    testeConsulta(1000000);
    testeExames(1000000);

    return 0;
}

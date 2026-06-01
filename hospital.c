#include <stdio.h>
#include <time.h>
#include <locale.h> 
#include "hospital.h"



Paciente pilha[MAX_SIZE]; // pilha emergencia
int topo = -1;

Paciente fila[MAX_SIZE]; // fila consulta
int inicio = 0, fim = 0;

Paciente circ[MAXC]; // fila circular exames
int ic = 0, fc = 0, total = 0;

void cadastrarPaciente() {
    Paciente p = {0};
    
    printf("Nome do paciente: ");
    scanf(" %49[^\n]", p.name);
    time(&p.timestamp);
    printf("Entrada: %s", ctime(&p.timestamp));

    printf("Idade do paciente: ");
    scanf("%d", &p.idade);

    printf("Gravidade do paciente (1-5): ");
    scanf("%d", &p.gravidade);

    if  (p.gravidade < 1 || p.gravidade > 5) {
        printf("Gravidade do paciente inválida!\n");
        return;
    }
    
    // gravidade
        printf("Tipo de atendimento:\n");
        if (p.gravidade >= 4) {
            if (topo < MAX_SIZE - 1) {
                pilha[++topo] = p;
                printf("1 - Emergência (Grau de Risco: %d)\n", p.gravidade);
                printf("Paciente enviado para EMERGÊNCIA!\n");

            } else {
                printf("A emergência esta cheia!\n");
            }
        }
        else {
            printf("2 - Consulta\n");
            printf("3 - Exame\n");
            scanf("%d", &p.tipo_atendimento);

        
        if (p.tipo_atendimento < 1 || p.tipo_atendimento > 3) {
                printf("Tipo de atendimento inválido!\n");
                return;
        }
                
        // consulta
             else if (p.tipo_atendimento == 2) {
                if (fim < MAX_SIZE) {
                    fila[fim++] = p;
                    printf("Paciente enviado para CONSULTA!\n");

            }   else {
                    printf("A fila de consulta esta cheia!\n");
                }
            }
        // exames
            else if (p.tipo_atendimento == 3) {
        // remove automaticamente o mais antigo
                if (total == MAXC) {
                    ic = (ic + 1) % MAXC;
                    total--;
                }
                circ[fc] = p;
                fc = (fc + 1) % MAXC;
                total++;
                printf("Paciente enviado para EXAMES!\n");
            }
        }
    }
    // atender paciente =========================================================================================
void atenderPaciente() {
    int setor;
    printf("1 - Emergência\n");
    printf("2 - Consulta\n");
    printf("3 - Exames\n");

    printf("Qual setor deseja escolher? \n");
    scanf("%d", &setor);

// emergencia
    if (setor == 1) {
        if (topo >= 0) {
            time(&pilha[topo].atendimento);
            printf("O paciente %s foi atendido às %s",
                pilha[topo].name,
                ctime(&pilha[topo].atendimento));
            topo--;

        } else {
            printf("Não há nenhum paciente na emergência.\n");
            }
        }
// consulta
    else if (setor == 2) {
        if (inicio < fim) {
            time(&fila[inicio].atendimento);
            printf("O paciente %s foi atendido às %s",
                fila[inicio].name,
                ctime(&fila[inicio].atendimento));
            inicio++;

        } else {
            printf("Não há nenhum paciente na consulta!\n");
        }
    }
// exames
    else if (setor == 3) {
        if (total > 0) {
            time(&circ[ic].atendimento);
            printf("O paciente %s foi atendido às %s",
                circ[ic].name,
                ctime(&circ[ic].atendimento));
            ic = (ic + 1) % MAXC;
            total--;

        } else {
            printf("Não há nenhum paciente nos exames!\n");
        }
    }
}
// mostrar paciente ======================================================================================================
void mostrarPaciente() {
    int i;
    // emergencia
    printf("\n===== Emergência =====\n");

    if (topo == -1) {
        printf("Não há nenhum paciente na emergência!\n");
    } else {
        for (i = topo; i >= 0; i--) {
            printf("Nome: %s\n", pilha[i].name);
            printf("Idade: %d\n", pilha[i].idade);
            printf("Gravidade: %d\n", pilha[i].gravidade);
            printf("Entrada: %s", ctime(&pilha[i].timestamp));
            printf("-----------------\n");
        }
    }
    // consulta
    printf("\n===== Consulta =====\n");

    if (inicio == fim) {
        printf("Não há nenhum paciente na consulta!\n");
    } else {
        for (i = inicio; i < fim; i++) {
            printf("Nome: %s\n", fila[i].name);
            printf("Idade: %d\n", fila[i].idade);
            printf("Gravidade: %d\n", fila[i].gravidade);
            printf("Entrada: %s", ctime(&fila[i].timestamp));
            printf("-----------------\n");
        }
    }
    // exames
    printf("\n===== Exames =====\n");
    if (total == 0) {
        printf("Não há nenhum paciete nos exames!\n");
    } else {
        int pos = ic;
        for (i = 0; i < total; i++) {
            printf("Nome: %s\n", circ[pos].name);
            printf("Idade: %d\n", circ[pos].idade);
            printf("Gravidade: %d\n", circ[pos].gravidade);
            printf("Entrada: %s", ctime(&circ[pos].timestamp));
            printf("-----------------\n");
            pos = (pos + 1) % MAXC;
        }
    }
}
// transferir paciente ===================================================================================================
void transferirPaciente() {
    int setorAtual, setorNovo;
    Paciente temp;

    printf("Setores:\n");
    printf("1 - Emergência\n");
    printf("2 - Consulta\n");
    printf("3 - Exames\n");

    printf("Escolha o setor onde se encontra o paciente: ");
    scanf("%d", &setorAtual);

    printf("Escolha para onde deseja transferir o paciente: \n");
    scanf("%d", &setorNovo);

// remover da emergencia
    if (setorAtual == 1) {
        if (topo >= 0) {
            temp = pilha[topo];
            topo--;

        } else {
            printf("A emergencia esta vazia!\n");
            return;
        }
    }
// remover da consulta
    else if (setorAtual == 2) {
        if (inicio < fim) {
            temp = fila[inicio];
            inicio++;
                    
            if (inicio == fim) {
                inicio = 0;
                fim = 0;
            }
        } else {
            printf("A consulta esta vazia!\n");
            return;
        }
    }
// remover dos exames
    else if (setorAtual == 3) {
        if (total > 0) {
            temp = circ[ic];
            ic = (ic + 1) % MAXC;
            total--;

        } else {
            printf("Não há pacientes nos exames!\n");
            return;
        }
    }
    
    time(&temp.transferencia);
    printf("Paciente %s transferido às %s",
       temp.name,
       ctime(&temp.transferencia));
       
// inserir na emergencia
    if (setorNovo == 1) {
        if (topo < MAX_SIZE - 1) {
            pilha[++topo] = temp;
            printf("O paciente %s foi transferido para EMERGENCIA!\n", temp.name);
                    
        } else {
            printf("A emergencia esta cheia!\n");
        }
    }
// inserir na consulta
    else if (setorNovo == 2) {
        if (fim < MAX_SIZE) {
            fila[fim++] = temp;
            printf("O paciente %s foi transferido para CONSULTA!\n", temp.name);

        } else {
            printf("A consulta esta cheia!\n");
        }
    }
// inserir nos exames
    else if (setorNovo == 3) {
        if (total == MAXC) {
            ic = (ic + 1) % MAXC;
            total--;
        }
        circ[fc] = temp;
        fc = (fc + 1) % MAXC;
        total++;
        printf("O paciente %s foi transferido para EXAMES!\n", temp.name);
    }
}

void relatorio() {
printf("\n===== RELATÓRIOS =====\n");
    
// Emergência
printf("\nEmergência — Total: %d paciente(s)\n", topo + 1); // pega os índices e add + 1, totalizando o numero de elementos 
if (topo == -1) { // se o topo for vazio printa vazio
    printf("Nenhum paciente.\n");
} else {
    for (int i = topo; i >= 0; i--) { // percorre a pilha, em cada paciente
        printf("Nome: %s | Idade: %d | Gravidade: %d | Entrada: %s",
                     pilha[i].name, pilha[i].idade, pilha[i].gravidade, ctime(&pilha[i].timestamp));
    }
}
    
// Consulta
printf("\nConsulta — Total: %d paciente(s)\n", fim - inicio);
if (inicio == fim) {
    printf("Nenhum paciente.\n");
} else {
    for (int i = inicio; i < fim; i++) { // percorre do inicio ao fim
        printf("Nome: %s | Idade: %d | Gravidade: %d | Entrada: %s",
                     fila[i].name, fila[i].idade, fila[i].gravidade, ctime(&fila[i].timestamp));
    }
}
    
// Exames
printf("\nExames — Total: %d paciente(s)\n", total);
if (total == 0) {
    printf("Nenhum paciente.\n");
} else {
    int pos = ic;
    for (int i = 0; i < total; i++) {
        printf("Nome: %s | Idade: %d | Gravidade: %d | Entrada: %s",
                     circ[pos].name, circ[pos].idade, circ[pos].gravidade, ctime(&circ[pos].timestamp));
        pos = (pos + 1) % MAXC; // pos volta pra 0 apos  chegar em 8
        }
    }
}
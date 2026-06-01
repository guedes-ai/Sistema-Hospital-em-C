#include <stdio.h>
#include <windows.h>
#include "hospital.h"
#include <locale.h> 

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese");

    
    int menu;

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Atender paciente\n");
        printf("3 - Mostrar pacientes\n");
        printf("4 - Transferir pacientes\n");
        printf("5 - Relatórios\n");
        printf("6 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                cadastrarPaciente();
                break;
                
            case 2:
                atenderPaciente();
                break;

            case 3:
                mostrarPaciente();
                break;

            case 4:
                transferirPaciente();
                break;

            case 5:
                relatorio();
                break;

            case 6:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while(menu != 6);
    printf("Encerrando o sistema... Obrigado!\n");
    return 0;
}
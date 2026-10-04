#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

int main() {
    //Inicializa a aleatoriedade para as viaturas
    srand(time(NULL)); 

    int opcao = 0;
    do {
        system("cls"); 
        printf("\n=== SISTEMA DE RESGATE INTEGRADO ===\n");          //lista do CLI(interface) definido para o LOBBY principal
        printf("1 - Gestao de Operadores\n");
        printf("2 - Gestao de Frota e Radar\n");
        printf("3 - Gestao de Missoes\n");
        printf("0 - Sair\n");
        printf("------------------------------------\n");
        printf("Escolha: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = -1; 
            int c; while ((c = getchar()) != '\n' && c != EOF); 
        }

        switch(opcao) {
            case 1: {
                int op1;
                system("cls");
                printf("\n--- GESTAO DE OPERADORES ---\n");         //lista do CLI(interface) definido para os operadores
                printf("1 - Cadastrar Novo Operador\n");
                printf("2 - Listar Equipe Completa\n");
                printf("3 - Buscar por Nome (Ver Status)\n"); //Opção integrada
                printf("0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op1);

                if(op1 == 1) cadastrarOperador();
                else if(op1 == 2) listarOperadores();
                else if(op1 == 3) buscarOperadorNome();
                break;
            }

            case 2:
                menuFrota(); 
                break;

            case 3:
                menuMissoes(); 
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
                break;
        }
    } while (opcao != 0);

    return 0;
}

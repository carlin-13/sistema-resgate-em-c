#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h" 

//Banco de Dados local limitado
Operador listaOps[100];
int qtdOps = 0;

//Função para evitar IDs repetidos (Requisito do PDF)
int verificarIdDuplicado(int id) {
    for (int i = 0; i < qtdOps; i++) {
        if (listaOps[i].id == id) return 1;
    }
    return 0;
}

void cadastrarOperador() {
    if (qtdOps >= 100) {
        printf("\n[ERRO] Limite de equipe atingido!\n");
        return;
    }

    printf("\n--- NOVO CADASTRO DE OPERADOR ---\n");
    int idTemp, valido = 0;

    do {
        printf("Digite o ID (numero unico): ");
        scanf("%d", &idTemp);
        
        //Limpeza de buffer (Vassoura) para não pular o nome depois
        int c; while ((c = getchar()) != '\n' && c != EOF) { }

        if (idTemp <= 0) printf("[ERRO] ID deve ser maior que zero.\n");
        else if (verificarIdDuplicado(idTemp)) printf("[ERRO] ID ja existe!\n");
        else valido = 1;
    } while (!valido);

    listaOps[qtdOps].id = idTemp;

    printf("Nome Completo: ");
    fgets(listaOps[qtdOps].nome, 50, stdin);
    listaOps[qtdOps].nome[strcspn(listaOps[qtdOps].nome, "\n")] = 0; 
    
    printf("Cargo (ex: Piloto, Medico): ");
    fgets(listaOps[qtdOps].cargo, 30, stdin);
    listaOps[qtdOps].cargo[strcspn(listaOps[qtdOps].cargo, "\n")] = 0; 

    printf("Status Inicial (1-Livre, 0-Ocupado): ");
    scanf("%d", &listaOps[qtdOps].status);
    
    int c; while ((c = getchar()) != '\n' && c != EOF) { }

    qtdOps++;
    printf(">> Operador cadastrado com SUCESSO!\n");
    system("pause");
}

void listarOperadores() {
    printf("\n--- LISTA DE EQUIPE ---\n");
    if (qtdOps == 0) printf("Nenhum operador cadastrado.\n");
    else {
        for(int i=0; i < qtdOps; i++) {
            printf("ID: %03d | Nome: %-20s | Cargo: %-15s | Status: %s\n", 
                listaOps[i].id, listaOps[i].nome, listaOps[i].cargo,
                (listaOps[i].status == 1 ? "LIVRE" : "EM MISSAO"));
        }
    }
    printf("-----------------------\n");
    system("pause");
}

//Função de Busca completa 
void buscarOperadorNome() {
    char termo[50];
    
    //Limpeza de buffer crucial para o fgets funcionar após o scanf do menu
    int c; while ((c = getchar()) != '\n' && c != EOF) { }

    printf("\n--- BUSCAR OPERADOR ---\n");
    printf("Digite o nome (ou parte dele): ");
    
    fgets(termo, 50, stdin);
    termo[strcspn(termo, "\n")] = 0; 

    printf("\n--- RESULTADO DA BUSCA ---\n");
    int achou = 0;
    
    for(int i=0; i < qtdOps; i++) {
        //strstr: Requisito funcional para busca parcial
        if (strstr(listaOps[i].nome, termo) != NULL) {
            printf(">> ID: %d|Nome: %-20s|Cargo: %-15s|Status: %s\n", 
                listaOps[i].id, 
                listaOps[i].nome, 
                listaOps[i].cargo,
                (listaOps[i].status == 1 ? "LIVRE" : "EM MISSAO"));
            achou = 1;
        }
    }
    
    if(!achou) printf("Nenhum operador encontrado com o termo '%s'.\n", termo);
    printf("\n");
    system("pause");
}

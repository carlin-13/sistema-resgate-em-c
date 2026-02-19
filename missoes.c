#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h" // Puxa as structs

// --- IMPORTANTE: CONECTANDO COM OS OUTROS ARQUIVOS ---
extern Operador listaOps[];
extern int qtdOps;
extern Viatura frota[];
extern int qtdViaturas;

Missao listaMissoes[100];
int qtdMissoes = 0;

void buscarMissaoPorId() {
    int idBusca;
    printf("\nDigite o ID da Missao: ");
    scanf("%d", &idBusca);
    
    int enc = 0;
    for(int i=0; i<qtdMissoes; i++) {
        if(listaMissoes[i].id == idBusca) {
            printf(">> ACHOU: Missao %d | %s | Op: %d | Via: %d\n", 
                listaMissoes[i].id, listaMissoes[i].descricao, 
                listaMissoes[i].idOperador, listaMissoes[i].idViatura);
            enc = 1;
        }
    }
    if(!enc) printf("Missao nao encontrada.\n");
    system("pause");
}

void cadastrarMissao() {
    printf("\n--- NOVA MISSAO ---\n");
    if (qtdOps == 0 || qtdViaturas == 0) {
        printf("[ERRO] Cadastre Operadores e Viaturas antes!\n");
        system("pause"); return;
    }

    Missao nova;
    nova.id = qtdMissoes + 1;

    // Limpeza
    int c; while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Data: "); fgets(nova.data, 12, stdin); nova.data[strcspn(nova.data, "\n")] = 0;
    printf("Descricao: "); fgets(nova.descricao, 100, stdin); nova.descricao[strcspn(nova.descricao, "\n")] = 0;

    int idOp, opValido = 0;
    do {
        printf("ID Operador: "); scanf("%d", &idOp);
        for(int i=0; i<qtdOps; i++) if(listaOps[i].id == idOp) opValido = 1;
        if(!opValido) printf("Operador nao encontrado!\n");
    } while(!opValido);
    nova.idOperador = idOp;

    int idVia, viaValida = 0;
    do {
        printf("ID Viatura: "); scanf("%d", &idVia);
        for(int i=0; i<qtdViaturas; i++) if(frota[i].id == idVia) viaValida = 1;
        if(!viaValida) printf("Viatura nao encontrada!\n");
    } while(!viaValida);
    nova.idViatura = idVia;

    nova.status = 1; 
    listaMissoes[qtdMissoes] = nova;
    qtdMissoes++;
    printf(">> MISSAO GRAVADA!\n");
    system("pause");
}

void listarMissoes() {
    printf("\n--- HISTORICO ---\n");
    for(int i=0; i<qtdMissoes; i++) {
        printf("#%d | %s | Data: %s | Op: %d | Via: %d\n",
            listaMissoes[i].id, listaMissoes[i].descricao, listaMissoes[i].data,
            listaMissoes[i].idOperador, listaMissoes[i].idViatura);
    }
    printf("-----------------\n");
    system("pause");
}

void menuMissoes() {
    int op;
    do {
        system("cls");
        printf("\n1-Registrar | 2-Listar | 3-Buscar | 0-Voltar: ");
        scanf("%d", &op);
        if(op==1) cadastrarMissao();
        if(op==2) listarMissoes();
        if(op==3) buscarMissaoPorId();
    } while(op!=0);
}

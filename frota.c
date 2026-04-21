#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "dados.h" 

#define TAM_MAPA 10
#define TAM_FROTA 100 

// Variáveis Globais da Frota
Viatura frota[TAM_FROTA];
int qtdViaturas = 0;
int dadosIniciados = 0; 

// Funções Auxiliares
int sortearPosicao() { return rand() % TAM_MAPA; }

void inicializarFrotaTeste() {
    if(dadosIniciados) return; 
    
    frota[0].id = 101; strcpy(frota[0].tipo, "Helicoptero"); strcpy(frota[0].modelo, "Aguia-01");
    frota[0].x = sortearPosicao(); frota[0].y = sortearPosicao(); frota[0].status = 1;

    frota[1].id = 102; strcpy(frota[1].tipo, "Ambulancia"); strcpy(frota[1].modelo, "SAMU-B");
    frota[1].x = sortearPosicao(); frota[1].y = sortearPosicao(); frota[1].status = 1;

    frota[2].id = 103; strcpy(frota[2].tipo, "Drone"); strcpy(frota[2].modelo, "Mavic-Pro");
    frota[2].x = sortearPosicao(); frota[2].y = sortearPosicao(); frota[2].status = 1;

    qtdViaturas = 3; 
    dadosIniciados = 1; 
}

double calcularDistancia(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); 
}

int verificarIdViaturaDuplicado(int id) {
    for (int i = 0; i < qtdViaturas; i++) {
        if (frota[i].id == id) return 1;
    }
    return 0;
}

void cadastrarViatura() {
    if (qtdViaturas >= TAM_FROTA) { printf("\nGaragem cheia!\n"); return; }

    printf("\n--- NOVA VIATURA ---\n");
    int idTemp;
    do {
        printf("ID da Viatura: ");
        scanf("%d", &idTemp);
        int c; while ((c = getchar()) != '\n' && c != EOF) { } 

        if (idTemp <= 0) printf("[ERRO] ID invalido.\n");
        else if (verificarIdViaturaDuplicado(idTemp)) printf("[ERRO] ID ja existe.\n");
        else break;
    } while (1);

    frota[qtdViaturas].id = idTemp;

    printf("Tipo (ex: Drone): ");
    fgets(frota[qtdViaturas].tipo, 30, stdin);
    frota[qtdViaturas].tipo[strcspn(frota[qtdViaturas].tipo, "\n")] = 0;

    printf("Modelo (ex: Aguia-01): ");
    fgets(frota[qtdViaturas].modelo, 30, stdin);
    frota[qtdViaturas].modelo[strcspn(frota[qtdViaturas].modelo, "\n")] = 0;

    frota[qtdViaturas].x = sortearPosicao(); 
    frota[qtdViaturas].y = sortearPosicao();
    frota[qtdViaturas].status = 1; 
    qtdViaturas++;
    printf(">> Sucesso! Posicao sorteada: (%d, %d)\n", frota[qtdViaturas-1].x, frota[qtdViaturas-1].y);
    system("pause");
}

void listarViaturas() {
    printf("\n--- FROTA DISPONIVEL ---\n");
    for (int i = 0; i < qtdViaturas; i++) {
        printf("ID: %d | %-12s | %-10s | Loc: (%d,%d) | %s\n",
            frota[i].id, frota[i].tipo, frota[i].modelo,
            frota[i].x, frota[i].y,
            (frota[i].status == 1 ? "LIVRE" : "OCUPADA"));
    }
    printf("------------------------\n");
    system("pause");
}

void acionarRadar() {
    if (qtdViaturas == 0) { printf("Sem viaturas cadastradas!\n"); return; }
    int xAc, yAc;
    
    printf("\n--- CENTRAL DE RADAR ---\n");
    do { 
        printf("Digite coordenada X do acidente (0-9): "); scanf("%d", &xAc);
        printf("Digite coordenada Y do acidente (0-9): "); scanf("%d", &yAc);
        if(xAc < 0 || xAc > 9 || yAc < 0 || yAc > 9) printf("[ERRO] Coordenada invalida!\n");
        else break;
    } while (1); 

    // Aqui irá ser desenhado um map contendo as viaturas 
    printf("\n      MAPA OPERACIONAL\n");
    printf("     0  1  2  3  4  5  6  7  8  9\n");
    printf("    -------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d |", i);
        for (int j = 0; j < 10; j++) {
            int plot = 0;
            for(int k=0; k<qtdViaturas; k++) {
                if(frota[k].x == i && frota[k].y == j) {
                    printf(frota[k].status == 1 ? " V " : " O "); 
                    plot = 1; break;
                }
            }
            if(!plot) {
                if(i == xAc && j == yAc) printf(" X ");
                else printf(" . ");
            }
        }
        printf("|\n");
    }
    printf("    -------------------------------\n");
    
    // Legenda 
    printf(" LEGENDA: [V] Livre  [O] Ocupado\n");
    printf("          [X] Acidente [.] Vazio\n");
    printf("-----------------------------------\n");

    // Busca de Viatura Mais Próxima
    int idMais = -1; 
    double menorDist = 999.0;
    for(int i=0; i<qtdViaturas; i++) {
        if(frota[i].status == 1) {
            double d = calcularDistancia(frota[i].x, frota[i].y, xAc, yAc);
            if(d < menorDist) { menorDist = d; idMais = frota[i].id; }
        }
    }

    if(idMais != -1) {
        printf("\n>> DESPACHANDO VIATURA ID: %d <<\n", idMais);
        for(int i=0; i<qtdViaturas; i++) {
            if(frota[i].id == idMais) frota[i].status = 0;
        }
    } else {
        printf("\n>> ALERTA: Nenhuma viatura livre!\n");
    }
    system("pause");
}

void menuFrota() {
    inicializarFrotaTeste();
    int op;
    do {
        system("cls");
        printf("\n=== GESTAO DE FROTA E RADAR ===\n");
        printf("1 - Cadastrar Nova Viatura\n");
        printf("2 - Listar Todas as Viaturas\n");
        printf("3 - Acionar Radar de Emergencia\n");
        printf("0 - Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op);
        if(op==1) cadastrarViatura();
        if(op==2) listarViaturas();
        if(op==3) acionarRadar();
    } while(op!=0);

}

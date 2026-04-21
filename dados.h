// Utilizei aqui para guardar as structs que irei utilizar 

#ifndef DADOS_H
#define DADOS_H

// Estrutura do Operador
typedef struct {
    int id;
    char nome[50];
    char cargo[30];
    int status; // 1-Livre, 0-Ocupado
} Operador;

// Estrutura da Viatura
typedef struct {
    int id;
    char tipo[30];    
    char modelo[30];  
    int x, y;         
    int status; // 1-Livre, 0-Ocupada
} Viatura; 

// Estrutura da Missão
typedef struct {
    int id;
    char data[12];
    char descricao[100];
    int idOperador;
    int idViatura;
    int status; // 1-Em Andamento, 2-Concluida
} Missao;


#endif

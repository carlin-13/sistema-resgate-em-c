//////////////Utilizei aqui para guardar as structs que irei utilizar 

#ifndef DADOS_H
#define DADOS_H

//Estrutura do Operador
typedef struct {
    int id;   //identificador
    char nome[50];  //nome com cache de até 50 slots
    char cargo[30];  //cargo com cache de até 30 slots
    int status; // 1-Livre, 0-Ocupado
} Operador;
//Estrutura da Viatura
typedef struct {
    int id;  //identificador
    char tipo[30];     //tipo com cache de até 30 slots
    char modelo[30];   ////modelo com cache de até 30 slots
    int x, y;         // variaveis que serão utilizadas na hora do mapa
    int status; // 1-Livre, 0-Ocupada
} Viatura; 

// Estrutura da Missão
typedef struct {
    int id;   //identificador
    char data[12];
    char descricao[100];
    int idOperador;    //identificador de operador
    int idViatura;     //identificador de viatura
    int status; // 1-Em Andamento, 2-Concluida
} Missao;


#endif

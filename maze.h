#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define MAX 50
typedef struct{
    char nome[100];
    int id;
    TipoPilha Movimentos;
}Item;
typedef struct Jogador *Apontador;
typedef struct Jogador{
    Item item;
    Apontador Prox;
}Jogador;
typedef struct{
    Apontador Frente, Tras;
    int Tamanho;
}FilaJogador;

//FUNCOES DA FILA
void FFVazia(FilaJogador* Fila);
void Enfileira(Item x, FilaJogador **Fila);
void Desenfileira(FilaJogador **Fila , Item *Item);
int FVazia(FilaJogador Fila);

//FUNCOES DE LISTA
void InsereLista(Item x, FilaJogador *Lista);
void Imprime(FilaJogador Lista);

//FUNCOES DO JOGO
void enfileiraAleatorio(FilaJogador* Lista, FilaJogador *Fila);
void realizaJogadas(FilaJogador **Fila);
void imprimeJogada(FilaJogador **Fila, int maze[][16]);
void jogando(FilaJogador *Fila);

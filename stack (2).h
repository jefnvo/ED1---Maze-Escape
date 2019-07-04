#include <stdlib.h>
#include <stdio.h>
#define MAX 100
typedef struct{
    int passeiEm[2];
}Passados;
typedef struct celula{
    int movements[2];
    Passados historico[MAX];
    struct celula *next;
}Celula;
typedef struct{
    Celula *Topo, *Fundo;
    int Tamanho;
    int Custo;
}TipoPilha;

void FPVazia(TipoPilha *Pilha);
void Empilha(int x, int y, TipoPilha *Pilha);
void Desempilha(TipoPilha *Pilha , int move[2] );
int  Tamanho(TipoPilha Pilha);
int PVazia(TipoPilha Pilha );
void ImprimePilha(TipoPilha Pilha);
#define stack_peek_x(Pilha) ((Pilha)->Topo == NULL ? NULL : (Pilha)->Topo->movements[0][0])
#define stack_peek_y(Pilha) ((Pilha)->Topo == NULL ? NULL : (Pilha)->Topo->movements[0][0])

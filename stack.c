#include "stack.h"
#include "list.h"
void FPVazia(TipoPilha *Pilha){
    Pilha->Topo=(Celula*) malloc(sizeof(Celula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->next = NULL;
    Pilha->Tamanho = 0;
    Pilha->Custo = 0;
}
int PVazia(TipoPilha Pilha ){
    return ( Pilha.Topo == Pilha.Fundo );
}
void Empilha(int x, int y, TipoPilha *Pilha ){
    Celula* Aux;
    Aux = (Celula*) malloc (sizeof(Celula));
    Pilha->Topo->movements[0]=x;
    Pilha->Topo->movements[1]=y;
    Pilha->Topo->historico->passeiEm[0]=x;
    Pilha->Topo->historico->passeiEm[1]=y;
    Pilha->Custo+=1;
    Aux ->next = Pilha ->Topo;
    Pilha ->Topo = Aux;
    (Pilha ->Tamanho)++;
}
void Desempilha(TipoPilha *Pilha , int move[2] ){
    Celula* q;
    if(PVazia(*Pilha)){
        printf ( "Erro : lista vazia\n" ) ;
    return;
    }
    q = Pilha ->Topo;
    Pilha ->Topo=q->next;
    move[0]=q->next->movements[0];
    move[1]=q->next->movements[1];
    free(q);
    (Pilha->Tamanho)--;
}
int Tamanho(TipoPilha Pilha){
    return ( Pilha.Tamanho);
}
void ImprimePilha(TipoPilha Pilha){
    Celula* Aux;
    Aux = Pilha.Topo->next;
    while (Aux != NULL) {
        printf("Movimento em x: %d\n", Aux ->movements[0]);
        printf("Movimento em y: %d\n", Aux ->movements[1]);
        Aux = Aux -> next;
    }
}

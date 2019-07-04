#include "maze.h"
int main() {
    FilaJogador lista,fila;
    Item cad;
    int i,op,subOp;
    FFVazia(&lista);
    FFVazia(&fila);
    printf("Digite o numero de jogadores que irao participar\n");
    scanf("%d", &subOp);
    for(i=0;i<subOp;i++){
        system("cls");
        printf("Seu id eh: %d\nDiga-nos o seu nome: \n",i);
        cad.id=i;;
        scanf("%s", cad.nome);
        InsereLista(cad,&lista);
    }
    printf("Vamos enfileirar aleatoriamente os jogadores na fila.\n\n\n\n");
    system("cls");
    enfileiraAleatorio(&lista,&fila);
    jogando(&fila);
}

#include "maze.h"
void FFVazia(FilaJogador* Fila){
    Fila->Frente = (Apontador) malloc (sizeof(Jogador));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
    Fila->Tamanho=0;
}

int FVazia(FilaJogador Fila ){
    return ( Fila.Frente == Fila.Tras );
}
void Enfileira (Item x, FilaJogador **Fila){
    FilaJogador *FilaAux=*Fila;
    FilaAux->Tras->Prox = (Apontador) malloc (sizeof(Jogador));
    FilaAux->Tras = FilaAux->Tras->Prox;
    FilaAux->Tras->item = x;
    FilaAux->Tras->Prox = NULL;
    (FilaAux->Tamanho)++;
}
void Desenfileira (FilaJogador **Fila , Item *Item){
    Apontador q;
    FilaJogador *FilaAux = *Fila;
    if(FVazia(*FilaAux)){
        printf ( "Erro fila esta vazia\n" );
        return;
    }
    q = FilaAux->Frente;
    FilaAux->Frente = FilaAux->Frente->Prox;
    *Item = FilaAux->Frente->item;
    free(q);
    (FilaAux->Tamanho--);
}
//OPERACOES DE LISTA

void InsereLista(Item x, FilaJogador *Lista){
    Lista -> Tras -> Prox = (Apontador) malloc(sizeof(Jogador));
    Lista -> Tras = Lista -> Tras -> Prox;
    Lista -> Tras -> item = x;
    Lista -> Tras -> Prox = NULL;
    FPVazia(&(Lista->Tras->item.Movimentos));
    (Lista->Tamanho)++;
}

void Imprime(FilaJogador Lista){
    Apontador Aux;
    Aux = Lista.Frente->Prox;
    while (Aux != NULL) {
        printf("Nome: %s\n", Aux -> item.nome);
        printf("ID: %d\n", Aux -> item.id);
        Aux = Aux -> Prox;
    }
}

//Funcoes do jogo
void enfileiraAleatorio(FilaJogador* Lista, FilaJogador *Fila){
    Item cad;
    Apontador aux,q;
    int i=0,j,v[MAX];

    //Funcao para gerar numeros aleatorios distintos
    for(i=0; i<Lista->Tamanho; i++){
		v[i] = (rand()%Lista->Tamanho);
		for(j=0; j<i; j++){
			if(v[j] == v[i]){
				v[i] = (rand()%Lista->Tamanho);
				j=-1;
			}
		}
	}

    i=0;
    while(Lista->Frente!=NULL){
        //lista de um elemento
        if(Lista->Tamanho==1){
            cad=Lista->Frente->Prox->item;
            free(Lista->Frente->Prox);
            Lista->Frente=Lista->Tras=NULL;
        }
        //lista de mais de um elemento
        else{
                aux=Lista->Frente;
                while(aux->Prox->item.id!=v[i])
                    aux=aux->Prox;
                q=aux->Prox;
                cad=q->item;
                aux->Prox=q->Prox;
                (Lista->Tamanho)--;
                free(q);
        }
        i++;
        Enfileira(cad,&Fila);
   }
}

void imprimeJogada(FilaJogador **Fila, int maze[][16]){
    Item cad;
    TipoPilha PilhaAux;
    FilaJogador *FilaAux = *Fila;
    int move[2],pos=0, card=0,i,j;
    char mazeDraw[4][16];
    //cria labirinto em mascara
    for(i=0;i<4;i++){
        for(j=0;j<16;j++){
            mazeDraw[i][j]='#';
        }
    }
    //desenfileira jogador
    Desenfileira(&FilaAux, &cad);
    //marca movimentacao na matriz
    for(i=0;i<4;i++){
        Desempilha(&cad.Movimentos, move);
        mazeDraw[move[0]]  [move[1]]=maze[move[0]][move[1]];
        Empilha(move[0],move[1],&PilhaAux);
    }
    //reempilha movimentos
    for(i=0;i<4;i++){
        Desempilha(&PilhaAux,move);
        Empilha(move[0],move[1],&cad.Movimentos);
    }
    free(&PilhaAux);
    //imprime matriz
    printf("Ola %s, segue sua jogada\n\n", cad.nome);
    printMazeDraw(mazeDraw);
    //coloca jogador no fim da fila
    Enfileira(cad,&Fila);
}
void realizaJogadas(FilaJogador **Fila){
    Item jogada;//armazena a o card de jogada do jogador
    FilaJogador *FilaAux=*Fila;
    int x,y,vetor[2];
    Desenfileira(&FilaAux, &jogada);
    printf("Ola %s, voce esta no nivel %d\n\n", jogada.nome, jogada.Movimentos.Tamanho+1);
    printf("Indique sua jogada nesse nivel: \n");
    scanf("%d", &y);
    x=jogada.Movimentos.Tamanho;
    if(y>15){
        printf("posicao invalida. Insira uma posicao valida\n");
        scanf("%d", &y);
    }
    Empilha(x,y,&jogada.Movimentos);
    Enfileira(jogada,&FilaAux);
}
void jogando(FilaJogador *Fila){
    int maze[4][16];
    newMaze(maze);
    int i,j=0;
    printf("\nRodada numero 0\n");
    for(i=0;i<4*Fila->Tamanho;i++)
        realizaJogadas(&Fila);
    imprimeJogada(&Fila,maze);
    printMaze(maze);
    imprimeJogada(&Fila,maze);
    printMaze(maze);
}

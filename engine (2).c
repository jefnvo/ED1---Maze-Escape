#include "engine.h"
void newMaze(int maze[][16]){
    int i,j,n;
    for(i=0;i<4;i++){
        for(j=0;j<16;j++){
            maze[i][j]=1;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            n=rand()%15;
            while(maze[i][n]==2)
               n=rand()%15;
            maze[i][n]=2;
        }
    }
}
void printMaze(int maze[][16]){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<16;j++)
            printf("%d   ", maze[i][j]);
        printf("\n\n");
    }
}
void printMazeDraw(char maze[][16]){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<16;j++){
            if(maze[i][j]==1||maze[i][j]==2)
                printf("%d   ", maze[i][j]);
            else
                printf("%c   ", maze[i][j]);
        }
        printf("\n\n");
    }
}



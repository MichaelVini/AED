/*   MICHAEL VINICIUS DA SILVA IZIDORO  120.877 NOTURNO  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAM 10
#define MAX_LINHA 20

typedef struct no *pme;
struct no{
    int col, val;
    pme prox;
};
typedef pme matriz[MAX_LINHA];

void inicializa(matriz m, int l){
    int i;
    for (i=0; i<l; i++){
        m[i] = NULL;
    }
}

void insere(matriz m, int i,int j, int val){
    pme novo, p;
    novo = (pme)malloc(sizeof(struct no));
    novo->val= val;
    novo->col = j;
    novo->prox = NULL;
    if (m[i]==NULL){
        m[i] = novo;
    } else {
        for(p = m[i]; p->prox!=NULL; p=p->prox);
        p->prox = novo;
    }
}

void imprimeMatrizAdjacencia(matriz m, int tlin, int tcol ){
    pme p;
    printf("\n Matriz de adjacencia:\n\n");
    printf("  ");
    for (int k = 0; k<tcol; k++){
        printf(" %d ", k+1);
    }
    printf("\n");
    for(int i=0; i<tlin; i++){
        printf("%d ", i+1);
        p = m[i];
        for(int j=0; j<tcol; j++)
            if ((p!=NULL) && (p->col==j)){
                printf(" %d ",p->val);
                p = p->prox;
            } else {
                printf(" 0 ");
            }
        printf("\n");
    }
    printf("\n");
}

void imprimeAdjacente(matriz m, int v, int adj){
    pme p;
    p = m[adj-1];
    printf("Os vertices adjacentes de %d sao: ", adj);
    for(int j=0; j<v; j++){
        if ((p!=NULL) && (p->col==j)){
            printf("%d ", (p->col)+1);
            p = p->prox;
        }
    }
    printf("\n");
}

void insereConexoes(matriz m){
    char conexoes[3];
    int x, y;

    while (conexoes[0] != '0'){
        scanf("%s", &conexoes);
        if (conexoes[0] != '0'){
            x = conexoes[0] - '0';
            y = conexoes[2] - '0';
            insere(m, x-1, y-1, 1);
        }
    }
}

void libera(matriz m, int l){
    pme p, q;
    int i;
    for(i=0; i<l; i++){
        p = m[i];
        while (p!=NULL){
            q = p;
            p = p->prox;
            free(q);
        }
    }
}

int main(void){
    matriz m;
    char grafoOrientado[MAX_TAM];
    int vertices, adj;

    printf("Informe o numero de vertices: ");
    scanf("%d", &vertices);

    inicializa(m,vertices);

    printf("O grafo e orientado? ");
    scanf("%s", &grafoOrientado);

    printf("Informe as conexoes, digite 0 para encerrar.\n");
    insereConexoes(m);

    printf("Informe o vertice que deseja saber seus adjacentes \n");
    scanf("%d", &adj);

    imprimeMatrizAdjacencia(m,vertices,vertices);
    imprimeAdjacente(m,vertices,adj);
    libera(m,vertices);
}

/* MICHAEL VINICIUS DA SILVA IZIDORO 120877 NOTURNO */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 20

typedef struct no *pme;
struct no{
    int col, val;
    pme prox;
};

struct cliente{
    int idCliente;
    int numeroFilmesAssistidos;
    int filmes[MAX_LINHA];
    char genero[MAX_LINHA];
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

void imprimeMatrizInteira(matriz m, int tlin, int tcol ){
    int i,j;
    pme p;

    printf("\nMatriz inteira:\n");
    for(i=0; i<tlin; i++){
        p = m[i];
        for(j=0; j<tcol; j++)
            if ((p!=NULL) && (p->col==j)){
                printf(" %d ",p->val);
                p = p->prox;
            } else {
                printf(" 0 ");
            }
        printf("\n");
    }
    printf("\n\n");
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

void insereFilmes(int lin, int col, struct cliente Cliente[lin], matriz m){
    int i, j;
    int nFilmesAssistidos,idFilme;
    char generoFilme;

    for(i=0; i<lin; i++){
        printf("\nQuantos filmes o cliente %d assistiu? ", i+1);
        scanf("%d", &nFilmesAssistidos);

        for(int k = 0; k<nFilmesAssistidos; k++){
            printf("Digite o numero do %do. filme assistido: ", k+1);
            scanf("%d", &idFilme);

            if(idFilme>col){
                printf("Filme invalido.\n");
                printf("Insira um valor correto\n\n");
                k--;
            } else {
                int ehIgual=0;

                while(ehIgual == 0){
                   printf("Digite o genero do filme (Letra Maiuscula): ");
                   scanf(" %c", &generoFilme);

                   if(generoFilme == 'A' || generoFilme == 'R' || generoFilme == 'S' ||
                    generoFilme == 'C' || generoFilme == 'M' || generoFilme == 'D' ||
                    generoFilme == 'F' || generoFilme == 'P'){
                        ehIgual = 1;
                        break;
                   }
                   printf("Genero invalido!!\n");
                }
                insere(m,i,idFilme-1,1);
                Cliente[i].idCliente = i+1;
                Cliente[i].numeroFilmesAssistidos = nFilmesAssistidos;
                Cliente[i].filmes[k] = idFilme;
                Cliente[i].genero[k] = generoFilme;
            }
        }
    }
}

void imprimeMatrizCondensada(int lin, int col, struct cliente Cliente[lin]){
    printf("Matriz Condensada:\n");
    for(int i=0; i<lin;i++){
        printf("Cliente: %d\n", i+1);
        printf("Filmes assistidos (filme e genero): \n");
        for(int j = 0;j<Cliente[i].numeroFilmesAssistidos;j++){
            printf("%d ", Cliente[i].filmes[j]);
            printf(" %c\n", Cliente[i].genero[j]);
        }
    }
}

int main(void){
    matriz m;
    int lin, col;

    printf("Insira a quantidade de filmes disponiveis no catalogo: ");
    scanf("%d", &col);
    printf("Insira a quantidade de clientes do servico: ");
    scanf("%d", &lin);

    inicializa(m,lin);
    struct cliente Cliente[lin];

    insereFilmes(lin, col, Cliente,m);
    imprimeMatrizInteira(m,lin,col);
    imprimeMatrizCondensada(lin,col,Cliente);
    libera(m,lin);
}

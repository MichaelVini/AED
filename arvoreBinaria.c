#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;
}TArv;
typedef TArv *PArv;

PArv cria(char c, PArv sae, PArv sad){
    PArv p= (PArv)malloc(sizeof(TArv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

void imprimePrefixa(PArv a){
    if(a!=NULL){
        printf("%c ", a->info);
        imprimePrefixa(a->esq);
        imprimePrefixa(a->dir);
    }
}

void imprime(PArv a){

    if(a!=NULL){
        printf("%c ", a->info);
        imprime(a->dir);
    }
}

void imprimeInfixa(PArv a){
    if(a!=NULL){
        imprimeInfixa(a->esq);
        printf("%c ", a->info);
        imprimeInfixa(a->dir);
    }
}

PArv libera(PArv a){
    if (a!=NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

int imprimeFilhos(PArv a, char c){

    if (a==NULL){
        return 0;
    }
    else if (c==a->info) {
        imprime(a->esq);
        return 1;
    }
    else if (imprimeFilhos(a->esq, c))
        return 1;
    else if (imprimeFilhos(a->dir, c))
        return 1;
}

int imprimeIrmaos(PArv a, char c){

    if (a==NULL){
        return 0;
    }
    else if (c==a->info) {
        imprime(a->dir);
        return 1;
    }
    else if (imprimeIrmaos(a->esq, c))
        return 1;
    else if (imprimeIrmaos(a->dir, c))
        return 1;
}

PArv criaArvore(PArv a){
    a = cria('A',
             cria('B',
                  cria('E',
                       cria('K', NULL,
                            cria('L', NULL, NULL)
                            ),
                       cria('F', NULL, NULL)
                       ),
                  cria('C',
                       cria('G', NULL, NULL),
                       cria('D',
                            cria('H',
                                 cria('M', NULL, NULL),
                                 cria('I', NULL,
                                      cria('J', NULL, NULL)
                                      )
                                 ),
                            NULL)
                        )
                    ), NULL
                );
    return a;
}

int main(void){

    int menu;
    PArv a;
    a = criaArvore(a);

    /*FILE *arq;
    arq = fopen ("arv.txt", "r");
    char temp[20];

    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo. \n");
        getchar();
        exit(0);
    }

    fscanf(arq, "%s", &temp);
    fclose(arq);
*/
    char filho, irmao;
    do {
        printf("\n\nSelecione a opcao desejada:");
        printf("\n1)Imprimir a arvore resultante em pre-ordem;");
        printf("\n2)Imprimir a arvore resultante em ordem infixa;");
        printf("\n3)Imprimir os filhos de um dado no;");
        printf("\n4)Imprimir os irmao de um dado no;");
        printf("\n5)Sair.\n");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                printf("\nImpressao pre-ordem: ");
                imprimePrefixa(a);
                break;

            case 2:
                printf("\nImpressao ordem infixa: ");
                imprimeInfixa(a);
                break;

            case 3:
                printf("\nQual o no que deseja conhecer os filhos: ");
                scanf(" %c", &filho);
                printf("\nFilhos do no %c: ", filho);
                imprimeFilhos(a, filho);
                break;

            case 4:
                printf("\nIndique o no: ");
                scanf(" %c", &irmao);
                printf("\nIrmao do no %c: ", irmao);
                imprimeIrmaos(a, irmao);
                break;

            default:
                if(menu == 5) continue;
                printf("\nOpcao invalida.\n");
                break;
        }
    } while (menu != 5);

    libera(a);
}


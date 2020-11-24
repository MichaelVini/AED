/* Nome: MICHAEL VINICIUS DA SILVA IZIDORO RA: 120877 TURMA: NOTURNO */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	struct lista* ant;
	char character;
	struct lista* prox;
}Lista;

typedef Lista *PLista2;

Lista *inicializaLista(){//Inicializa todas as variaveis como nulas ou zero.
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->character = ' ';

    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

Lista* InsereElementoNoFim(Lista *l, char letra){
	Lista* novo = (Lista*) malloc(sizeof(Lista));

	if (novo == NULL){
		return NULL;
	}
	novo->character = letra;
	novo->prox = NULL;

	if (l == NULL){
		novo->ant = NULL;
		l = novo;
		return novo;
	}
	else {
		Lista *aux;
		aux = l;

		while(aux->prox != NULL){
            aux = aux->prox;
		}
		aux->prox = novo;
		novo->ant = aux;
	}
	return l;
}

Lista *buscarLetra(Lista *l, char letra){
	PLista2 p;
	for (p=l; p!=NULL; p=p->prox){
		if (p->character == letra)
		return p;
	}
	return NULL; //Não achou o elemento
}

void trocaLetras(Lista* NoA, Lista* NoB){
  char aux = NoA->character;
  NoA->character = NoB->character;
  NoB->character = aux;
}

void imprimirLista(Lista* l){
    Lista* atual = l;
    while(atual->ant != NULL)
        atual = atual->ant;

    while(atual != NULL){
        printf("%c", atual->character);
        atual = atual->prox;
    }
}

void liberarLista(Lista* l){
    if(l->prox != NULL)
        liberarLista(l->prox);
    free(l);
}

int main(void){
	Lista *Palavra = inicializaLista();
    Lista *Primeiro;
	Lista *NoA, *NoB;
	char palavraAserInserida[10];
	char letra1, letra2;

	printf("Digite a palavra que deseja alterar: \n");
	scanf("%s", palavraAserInserida);
	getchar();

	printf("Digite a letra que sera trocada de lugar: \n");
	scanf("%c", &letra1);
	getchar();

	printf("Digite a letra que sera trocada de lugar: \n");
	scanf("%c", &letra2);
	getchar();

	for(int i=0;i<strlen(palavraAserInserida);i++){
        if(i==0){
            Primeiro = InsereElementoNoFim(Palavra, palavraAserInserida[i]);
        } else{
            InsereElementoNoFim(Palavra, palavraAserInserida[i]);
        }
	}

	NoA = buscarLetra(Palavra, letra1);
	NoB = buscarLetra(Palavra, letra2);
	trocaLetras(NoA, NoB);
	imprimirLista(Palavra);
	liberarLista(Palavra);
}


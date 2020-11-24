/* MICHAEL VINICIUS DA SILVA IZIDORO RA: 120877 TURMA: NOTURNO */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PILHA 50

typedef struct {
    char Item[MAX_PILHA];
    //Variavel indica a posição do vetor que está o topo da pilha.
    int Topo;
} TPilha;

void TPilha_Inicia(TPilha *p) {
    //Topo recebe -1 indicando q a pilha está vazia
    p->Topo = -1;
}

int TPilha_Cheia (TPilha *p) {
    if(p->Topo == MAX_PILHA-1){
        return 1;
    } else {
        return 0;
    }
}

//Se a pilha estiver vazia essa função retorna 1, senão retorna 0.
int TPilha_Vazia(TPilha *p) {
    if(p->Topo == -1){
        return 1;
    } else {
        return 0;
    }
}

void TPilha_Insere (TPilha *p, char x){
    if(TPilha_Cheia(p) == 1){
        printf("\n ERRO: Pilha Cheia.\n");
    } else {
        //Determinar q o valor x seja inserido na proxima casa do vetor.
        p->Topo++;
        p->Item[p->Topo] = x;
    }
}

int ConsultaPilha(TPilha *p){
    if (p->Topo < 0){
        return -1;
    } else {
        printf("Versao posfix: \n");
        for (int i=p->Topo;i>=0;i--){
        printf ("%c", p->Item[p->Topo-i]);
        }
    }
}

int main(void) {
    //Criar ponteiro do tipo struct TPilha para os operadores e o posfi.
    TPilha *operadores;
    TPilha *posfix;
    TPilha *delimitadores;
    char vet[MAX_PILHA];

    //Alocar espaço na memoria para os ponteiros.
    operadores = (TPilha*)malloc(sizeof(TPilha));
    posfix = (TPilha*)malloc(sizeof(TPilha));
    delimitadores = (TPilha*)malloc(sizeof(TPilha));

    //Iniciar pilhas
    TPilha_Inicia(operadores);
    TPilha_Inicia(posfix);
    TPilha_Inicia(delimitadores);

    printf("Digite a expressao aritmetica infixa:\n");
    scanf("%s", &vet);

    for(int i = 0; i < strlen(vet);i++){
        //Caso sejá um operando, incluir no ponteiro posfix.
        if((vet[i] >= 65 && vet[i]<91) || (vet[i] >= 97 && vet[i]<123)){
            TPilha_Insere(posfix, vet[i]);
        } else if (vet[i] == '(' || vet[i] == ')'){
            TPilha_Insere(delimitadores, vet[i]);
        } else {
            TPilha_Insere(operadores, vet[i]);
        }
    }

    for(int i=0; i<=operadores->Topo; i++){
        TPilha_Insere(posfix, operadores->Item[i]);
    }

    printf(ConsultaPilha(posfix));

    free(posfix);
    free(operadores);
    free(delimitadores);
}

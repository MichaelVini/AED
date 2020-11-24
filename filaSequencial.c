/* MICHAEL VINICIUS DA SILVA IZIDORO RA: 120.877 TURMA: NOTURNO */
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 100

//Criar estrutura para as insformações do candidato.
typedef struct {
    int id;
    int nota;
    int prox;
    char convite;
} TVestibulando;

//Criar estrutura para fila.
typedef struct {
    int nElements; // Número de elementos armazenados na fila
    int primeiro;
    int ultimo;
    int posicaoLivre;
    TVestibulando elemento[MAX_FILA]; // Criação do elemento do tipo struct TVestibulando
} TFila;

 void cria_fila(TFila *fila){
    fila->nElements = 0;
    fila->posicaoLivre = 0;
    fila->primeiro = -1;
    fila->ultimo = -1;
 }

  int insere(TFila* fila, int id, int nota ,int posicao){
    if (fila->nElements == MAX_FILA){
        printf("Fila cheia!\n");
        return -1;
    }
    fila->elemento[posicao].id = id;
    fila->elemento[posicao].nota = nota;
    fila->elemento[fila->ultimo].prox = posicao;
    fila->elemento[posicao].prox = -1;
    fila->ultimo = posicao;
    fila->posicaoLivre = fila->posicaoLivre+1;
    fila->nElements++;
}

 void ordenaFila(TFila* fila, int candidatos){
     for(int i=0;i<candidatos-1; i++){
         for(int j=i+1; j<candidatos; j++){
             if(fila->elemento[i].nota < fila->elemento[j].nota){
                 TVestibulando aux;
                 aux = fila->elemento[i];
                 fila->elemento[i] = fila->elemento[j];
                 fila->elemento[j] = aux;
             }
         }
     }
 }

 void imprimeVestibulandos(TFila* fila, int candidatos){
     printf("-Impressao da Fila-\n");
     for(int i=0;i<candidatos; i++){
         printf("Candidato: %d, nota: %d\n", fila->elemento[i].id, fila->elemento[i].nota);
     }
     printf("\n");
 }

 void recebeAprovacao(TFila* fila, int candidatos, int vagas){
    int countNotas=0;
     for(int i=0;i<candidatos; i++){
         if(countNotas < vagas){
           printf("Resposta recebido do candidato de id %d (s/n): ", fila->elemento[i].id);
           scanf(" %c", &fila->elemento[i].convite);
           if(fila->elemento[i].convite == 's'){
               countNotas++;
           }
         } else {
             break;
         }
     }
 }

  void imprimeNovosAlunos(TFila* fila, int candidatos){
     printf("\n-Lista de Novos Alunos-\n");
     for(int i=0;i<candidatos; i++){
         if(fila->elemento[i].convite == 's'){
             printf("Candidato id: %d",fila->elemento[i].id);
             printf("\n");
         }
     }
 }

int proximaPosicaoLivre(TFila* fila){
    return fila->posicaoLivre;
}
 int main(void){

     int candidatos,vagas;
     TFila fila;
     cria_fila(&fila);

     printf("Quantidade de candidatos: ");
     scanf("%d", &candidatos);
     printf("Quantidade de vagas: ");
     scanf("%d", &vagas);
     printf("\n");

     for(int i=0;i<candidatos;i++){
        int posicao = proximaPosicaoLivre(&fila);
        int id, nota;

        printf("Numero Identificador do candidato: ");
        scanf("%d", &id);
        printf("Nota do candidato: ");
        scanf("%d", &nota);
        insere(&fila, id, nota, posicao);
        printf("Candidato Inserido.\n\n");
     }
     ordenaFila(&fila, candidatos);
     imprimeVestibulandos(&fila, candidatos);
     recebeAprovacao(&fila, candidatos, vagas);
     imprimeNovosAlunos(&fila, candidatos);
 }


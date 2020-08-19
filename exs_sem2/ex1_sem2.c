#include <stdio.h>
#include <stdlib.h>

int main(void){

int numCandidatos;
int voto = 0;
int vencedor;

printf("Digite o numero de candidatos da eleicao: \n");
scanf("%d", &numCandidatos);

int *p;
int v=0;

/*Alocar memoria para o (numero de candidatos + 1), já que a posição [0] não será utilizada,
pois cada candidato terá o numero da sua posição.*/
p = (int *)malloc((numCandidatos + 1)*sizeof(int));

//Verificar erros na alocação de memoria.
if (p == NULL){
       printf("Erro na alocação de memória.");
     // Caso não haja erros ...
    } else {
        //Zerar todas as posiçoes do vetor
        for(int i = 0; i<numCandidatos+1; i++){
            p[i] = 0;
        }
        while(voto >= 0) {
            printf("Digite o numero do candidato para qual seu voto sera destinado. \n");
            printf("Ou digite um numero negativo para sair a qualquer momento. \n");
            scanf("%d", &voto);
            printf("------------------------------------------------------------------\n");

            if (voto == 0 || voto > numCandidatos){
               printf("Candidato nao existe.\n");
            }
            //Caso o candidato seja o numero 3 por exemplo, o valor do espaço na posição (p + 3) receberá um voto.
            // como p está direcionado para a posiçao [0] entao a posição (0 + 3) receberá o voto.
            *(p + voto) = *(p + voto) + 1;
        }
        for (int i = 1; i < numCandidatos + 1; i++) {
            printf("O Candidato numero %d possui %d votos.\n", i, p[i]);
            if (p[i] >= v){
            v = p[i];
            vencedor = i;
            }
        }
        printf("\nParabens!!! O candidato numero %d foi o vencedor com um total de %d votos.\n", vencedor, v);
    }
//Liberar espaço alocado.
free (p);
}

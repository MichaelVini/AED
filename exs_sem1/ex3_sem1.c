#include <stdio.h>
#include <stdlib.h>

struct InfoPessoas{
    char nome[30];
    int idade;
    float altura;
};

/*Função recebe o endereço de memória da struct Pessoa
e imprime os dados.*/
void Imprima_Dados(int numeroPessoas, struct InfoPessoas *Pessoa){

    for(int i=0; i<numeroPessoas; i++){
        printf("-----------\n");
        printf("%s \n", Pessoa[i].nome);
        printf("%d \n", Pessoa[i].idade);
        printf("%.2f \n", Pessoa[i].altura);

    }
}

int main(void){

    int numeroPessoas;

    printf("Digite o numero de cadastros que deseja realizar: \n");
    scanf("%d", &numeroPessoas);

    //-Criar um ponteiro do tipo (struct infoPessoas) chamado Pessoa.
    struct InfoPessoas *Pessoa;

    /*- Alocar na memória um espaço para estruturas do tipo InfoPessoas n vezes.
      - Direcionar o endereço da memória alocada para o ponteiro Pessoa.
      -A primeora parte (struct InfoPessoas *) força que o endereço de memória retornado
      pela função malloc seja do tipo struct InfoPessoas (casting).*/
    Pessoa = (struct InfoPessoas *)malloc(sizeof(struct InfoPessoas)*numeroPessoas);

    //Caso o ponteiro Pessoa não receba o endereço de memória alocado...
    if (Pessoa == NULL){
       printf("Erro na alocação de memória.");
       // Se der tudo certo, colocar os dados dentro do ponteiro Pessoa nas respectivas posições...
    } else {
          for(int i=0; i<numeroPessoas; i++){
          printf("Digite o nome: \n");
          scanf("%s", &Pessoa[i].nome);
          printf("Digite a idade: \n");
          scanf("%d", &Pessoa[i].idade);
          printf("Digite a altura: \n");
          scanf("%f", &Pessoa[i].altura);
          }
    }

    /*Passar o endereço de memória da struct Pessoa e o número de cadastros para
    a função Imprima_Dados.*/
    Imprima_Dados(numeroPessoas,Pessoa);

    //Liberar a memória alocada do ponteiro/vetor Pessoa.
    free(Pessoa);
}


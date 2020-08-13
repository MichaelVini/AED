#include <stdio.h>
#include <stdlib.h>

struct InfoPessoas{
    char nome[30];
    int idade;
    float altura;
};

/*Fun��o recebe o endere�o de mem�ria da struct Pessoa
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

    /*- Alocar na mem�ria um espa�o para estruturas do tipo InfoPessoas n vezes.
      - Direcionar o endere�o da mem�ria alocada para o ponteiro Pessoa.
      -A primeora parte (struct InfoPessoas *) for�a que o endere�o de mem�ria retornado
      pela fun��o malloc seja do tipo struct InfoPessoas (casting).*/
    Pessoa = (struct InfoPessoas *)malloc(sizeof(struct InfoPessoas)*numeroPessoas);

    //Caso o ponteiro Pessoa n�o receba o endere�o de mem�ria alocado...
    if (Pessoa == NULL){
       printf("Erro na aloca��o de mem�ria.");
       // Se der tudo certo, colocar os dados dentro do ponteiro Pessoa nas respectivas posi��es...
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

    /*Passar o endere�o de mem�ria da struct Pessoa e o n�mero de cadastros para
    a fun��o Imprima_Dados.*/
    Imprima_Dados(numeroPessoas,Pessoa);

    //Liberar a mem�ria alocada do ponteiro/vetor Pessoa.
    free(Pessoa);
}


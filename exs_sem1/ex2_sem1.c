#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char nome[30];
    int idade;
    float altura;
};

//Fun��o recebe o endere�o de mem�ria da struct infoPessoa
//e imprime os dados.
void Imprima_Dados( struct Pessoa *infoPessoa) {
    printf("%s \n", infoPessoa->nome);
    printf("%d \n", infoPessoa->idade);
    printf("%.2f \n", infoPessoa->altura);
}

int main(void) {

    //-Criar um ponteiro do tipo (struct Pessoa) chamado infoPessoa.
    struct Pessoa *infoPessoa;

    //- Alocar na memoria um espa�o para uma estrutura do tipo Pessoa.
    //- Direcionar o endere�o da mem�ria alocada para o ponteiro infoPessoa.
    infoPessoa = (struct Pessoa *)malloc(sizeof(struct Pessoa));

    if (infoPessoa == NULL) {
        printf("Erro na aloca��o de mem�ria.");
    } else {
        printf("Digite o nome da pessoa: \n");
        scanf("%s", &infoPessoa->nome);
        printf("Digite a idade: \n");
        scanf("%d", &infoPessoa->idade);
        printf("Digite a altura: \n");
        scanf("%f", &infoPessoa->altura);

        //Passar o endere�o de mem�ria da struct infoPessoa para
        //a fun��o Imprima_Dados.
        Imprima_Dados(infoPessoa);
    }
    //Liberar a mem�ria alocada para o ponteiro infoPessoa.
    free(infoPessoa);
}


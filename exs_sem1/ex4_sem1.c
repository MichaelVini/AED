#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void comparaStrings(char nomeDigitado[10]) {
    FILE *arquivo;

    arquivo = fopen("Nomes.txt", "r");

    char nomes[MAX][10];
    int i = 0;
    int stringsIguais = 0;

    while(!feof(arquivo)){
        fscanf(arquivo, "%s", nomes[i]);
        if(strcmp(nomeDigitado, nomes[i]) == 0){
            stringsIguais++;
        }
        i++;
    }

    fclose(arquivo);

    printf("%d pessoas. \n\n", stringsIguais);
}

int main(void){

    FILE *arquivo;

     char palavra[MAX][10];
     int i = 1;
     char n[10];

    //abrir o arquivo
    arquivo = fopen("Nomes.txt", "w");

    if(arquivo == NULL){
        printf("Não foi possivel abrir o arquivo. \n");
        getchar();
        exit(0);
    }

    while( strcmp(palavra[i-1],"FIM")!= 0){

    printf("- Digite um nome para ser armazenado no arquivo .txt. \n");
    printf("- Ou digite FIM para sair.\n");
    scanf("%s", palavra[i]);
    printf("----------------------------------------------------------\n");

    //armazenar string no arquivo com fprintf()
    fprintf(arquivo,"%s \n", palavra[i]);
    i++;
    }

    //Fechar o arquivo com fclose
    fclose(arquivo);
    printf("Dados gravados com sucesso!!\n");
    printf("Voce sera direcionado para outro menu!!\n\n");

    while(strcmp(n, "FIM") != 0){

        printf("-Digite um nome para verificar quantas pessoas exitem no arquivo .txt com esse mesmo nome: \n");
        printf("OBS: Lembre-se de digitar o nome corretamente (maiusculas e minusculas) assim como foi digitado anteriormente. \n");
        printf("-Ou digite FIM para encerrar a aplicacao. \n");
        scanf("%s", &n);

        comparaStrings(n);
    }


}

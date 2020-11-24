/* MICHAEL VINICIUS DA SILVA IZIDORO RA 120877 TURMA: NOTURNO*/
#include <stdio.h>
#include <stdlib.h>

struct produto{
    int codigo;
    char nome[30];
    float preco;
};

struct elemento {
    struct produto dados;
    struct elemento *prox; //Ponteiro para o próximo elemento
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista(){
    //Preencher o inicio da lista com NULL
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void destroi_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_lista_ordenada(Lista* li, struct produto prod){
    printf("Codigo do produto: \n");
    scanf("%d", &prod.codigo);
    printf("Nome do produto: \n");
    scanf("%s", &prod.nome);
    printf("Preco: \n");
    scanf("%f", &prod.preco);

    if(li == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = prod;
    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    } else {
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo < prod.codigo){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            //insere inicio
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_item_lista(Lista* li, int cod){
    if(li == NULL) return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.codigo != cod){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0; //Não encontrado

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int consulta_lista_prod(Lista* li, int codigo, struct produto *prod){
    if(li == NULL) return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.codigo != codigo) {
        no = no->prox;
    }
    if(no == NULL)
        printf("Produto nao encontrado.\n\n");
    else{
        *prod = no->dados;
        printf("%s\n", prod->nome);
        printf("R$%.2f\n", prod->preco);
        printf("\n");
    }
}

int main(void){
    struct produto dados_produto; //Estrutura que receberá os dados do produto.
    struct produto *p;
    p = &dados_produto;
    int codigo_produto, n, x=1;

    Lista *li;
    li = cria_lista();

    printf("Digite o numero de produtos que serao cadastrados: \n");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        insere_lista_ordenada(li, dados_produto);
        printf("Cadastrado com sucesso!!\n\n");
    }

    while(x != 0){
        printf("Digite (1) para consultar o preco de um produto: \n");
        printf("Digite (2) para excluir um produto: \n");
        printf("Digite (0) para sair: \n");
        scanf("%d", &x);

        if(x == 1){
            printf("Digite o codigo do produto para ser consultado: \n");
            scanf("%d", &codigo_produto);
            consulta_lista_prod(li, codigo_produto, &p);
        } else if (x == 2){
             printf("Digite o codigo do produto para ser excluido: \n");
             scanf("%d", &codigo_produto);
             remove_item_lista(li, codigo_produto);
             printf("Produto removido com sucesso!!\n\n");
        }
    }
    destroi_lista(li);
}

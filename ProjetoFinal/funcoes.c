#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct elemento {
    CLIENTE dados;
    struct elemento *prox;
} Elem;

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void apagaLista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li) -> prox;
        }
        free (li);
    }
}

int tamLista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}


int listaCheia(Lista *li){
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }

    return 0;
}

int insere_inicio_lista(Lista *li, CLIENTE cl){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }

    no->dados = cl;
    no->prox = (*li);
    *li = no;

    return 1;
}

int insere_final_lista(Lista *li,CLIENTE cl){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = cl;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        ELEM *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista(Lista *li,CLIENTE cl){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }

    no->dados = cl;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no ;
        return 1;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.id < cl.id){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_inicio_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    ELEM *no = *li;
    *li = (*li)->prox;
    free(no);
    return 1;
}


int remove_final_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    ELEM *ant , *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;

}

int remove_lista(Lista *li, int id){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.id != id){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta_lista_pos(Lista *li, int posicao, CLIENTE *cl){
    if(li == NULL || posicao < 0){
        return 0;
    }
    ELEM *no = *li;
    int i = 1;
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }else{
        *cl = no->dados;
        return 1;
    }

}


int consulta_lista_id(Lista *li, int id, CLIENTE *cl){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *cl = no->dados;
        return 1;
    }
}

int consulta_lista_nome(Lista *li, const char *nome, CLIENTE *cl){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && strncasecmp(no->dados.nome, nome, strlen(nome)) != 0){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *cl = no->dados;
        return 1;
    }
}

void sair(){
    printf("Salvando e saindo do programa...\n");
}

void menu(){
    printf("\n\n");
    printf("1 - inserir novo contato\n");
    printf("2 - Gerar e exibir relatorio de contatos \n");
    printf("3 - Gerar e exibir relatorio individual com busca por identificador\n");
    printf("4 - Gerar e exibir relatorio com busca por nome \n");
    printf("5 - Edicao de dados do contato, escolhido por identificador\n");
    printf("6 - Remover contato, escolhido por identificador\n");
    printf("7 - Sair e encerrar o programa\n");
    printf("\n");
    printf("Escolha a opcao: ");
}



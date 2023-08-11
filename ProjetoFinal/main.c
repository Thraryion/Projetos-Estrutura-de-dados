#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int numeroClientes = 0;

int ImprimeRelatorio (Lista *li);
CLIENTE ColetaDados (Lista *li);
void InserirContato(Lista *li);
void GerarRelatorio(Lista *li);
void GerarRelatorioID(Lista *li);
void GerarRelatorioNome(Lista *li);

int main()
{
    int I;
    Lista *li = criaLista();
    FILE *f;
    f = fopen("Contatos.bin", "rb");
    if(f != NULL )
    {
        CLIENTE cl;
        while (fread(&cl, sizeof(CLIENTE),1, f) ==1)
        {
            insere_lista(li,cl);
        }
        numeroClientes = tamLista(li);
        fclose(f);
    }
    else if (f == NULL)
    {
        printf("Arquivo nao existe! \n");
        fclose(f);
        fopen("Contatos.bin", "wb");
        fclose(f);
    }

//menu do programa
    do
    {
        menu();
        scanf("%d", &I);
        switch(I)
        {
        case 1:
            InserirContato(li);
            break;
        case 2:
            GerarRelatorio(li);
            break;
        case 3:
            GerarRelatorioID(li);
            break;
        case 4:
            GerarRelatorioNome(li);
            break;
        case 5:
            EditarContato(li);
            break;
        case 6:
            RemoverContato(li);
            case 7:
            sair();
            break;
        }
        system ("cls");
    }
    while ( I != 7);
    numeroClientes = tamLista(li);

    // Salva os dados e encerra o programa

   f = fopen("contatos.bin", "wb");
    for(int i = 0; i < numeroClientes; i++){
        CLIENTE Pesquisar;
        consulta_lista_pos(li, i+1, &Pesquisar);
        fwrite(&Pesquisar, sizeof(CLIENTE), 1, f);
    }

    apagaLista(li);
    fclose(f);

    return 0;
}

void InserirContato(Lista *li){
CLIENTE cl = ColetaDados(li);

insere_lista(li,cl);
int numeroClientes = tamLista(li);
}

CLIENTE ColetaDados (Lista *li) {
CLIENTE cl;
cl.id = tamLista(li) + 1;
    printf("ID do Cliente: %d\n\n", cl.id);

    printf("Digite o nome: ");
    limparBufferEntrada();
    fgets(cl.nome, sizeof(cl.nome), stdin);
    cl.nome[strcspn(cl.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o nome da empresa: ");
    fgets(cl.empresa, sizeof(cl.empresa), stdin);
    cl.empresa[strcspn(cl.empresa, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o nome do departamento: ");
    fgets(cl.departamento, sizeof(cl.departamento), stdin);
    cl.departamento[strcspn(cl.departamento, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o telefone: ");
    fgets(cl.telefone, sizeof(cl.telefone), stdin);
    cl.telefone[strcspn(cl.telefone, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o celular: ");
    limparBufferEntrada();
    fgets(cl.celular, sizeof(cl.celular), stdin);
    cl.celular[strcspn(cl.celular, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o email: ");
    limparBufferEntrada();
    fgets(cl.email, sizeof(cl.email), stdin);
    cl.email[strcspn(cl.email, "\n")] = '\0'; // Remove o caractere de nova linha

    return cl;
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int ImprimeRelatorio (Lista *li){

      for(int i = 1; i <= numeroClientes; i++){
        CLIENTE cl;
        consulta_lista_pos(li, i, &cl);
        printf("ID: %d\n", cl.id);
        printf("Nome: %s\n", cl.nome);
        printf("Empresa: %s\n", cl.empresa);
        printf("Departamento: %s\n", cl.departamento);
        printf("Telefone: %s\n", cl.telefone);
        printf("Celular: %s\n", cl.celular);
        printf("Email: %s\n\n", cl.email);

    }
    fflush(stdin);
    getch();
}
void GerarRelatorio(Lista *li){
     printf("\n");
    printf("Numero de clientes: %d\n\n", numeroClientes);
    ImprimeRelatorio (li);
}

void EditarContato(Lista *li) {
    printf("Digite o ID do contato que deseja editar: ");
    int id;
    scanf("%d", &id);

    CLIENTE cl1;
    if (consulta_lista_id(li, id, &cl1) == 0) {
        printf("Contato não encontrado.\n");
        return;
    }

    printf("Digite o nome: ");
    limparBufferEntrada();
    fgets(cl1.nome, sizeof(cl1.nome), stdin);
    cl1.nome[strcspn(cl1.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o nome da empresa: ");
    fgets(cl1.empresa, sizeof(cl1.empresa), stdin);
    cl1.empresa[strcspn(cl1.empresa, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o nome do departamento: ");
    fgets(cl1.departamento, sizeof(cl1.departamento), stdin);
    cl1.departamento[strcspn(cl1.departamento, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o telefone: ");
    fgets(cl1.telefone, sizeof(cl1.telefone), stdin);
    cl1.telefone[strcspn(cl1.telefone, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o celular: ");
    limparBufferEntrada();
    fgets(cl1.celular, sizeof(cl1.celular), stdin);
    cl1.celular[strcspn(cl1.celular, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o email: ");
    limparBufferEntrada();
    fgets(cl1.email, sizeof(cl1.email), stdin);
    cl1.email[strcspn(cl1.email, "\n")] = '\0'; // Remove o caractere de nova linha

    if (remove_lista(li, id) == 0) {
        printf("Erro ao remover o contato da lista.\n");
        return;
    }

    if (insere_lista(li, cl1) == 0) {
        printf("Erro ao inserir o contato na lista.\n");
        return;
    }

    printf("Contato editado com sucesso.\n");
}

void GerarRelatorioID(Lista *li) {
    int id;
    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("\n\n");
    CLIENTE Pesquisar;
    int encontrado = consulta_lista_id(li, id, &Pesquisar);
    if (!encontrado) {
        printf("Contato não encontrado!\n");
    } else {
        printf("ID: %d\n", Pesquisar.id);
        printf("Nome: %s\n", Pesquisar.nome);
        printf("Empresa: %s\n", Pesquisar.empresa);
        printf("Telefone: %s\n", Pesquisar.telefone);
        printf("Celular: %s\n", Pesquisar.celular);
        printf("Email: %s\n\n\n", Pesquisar.email);
    }
     printf("Pressione qualquer tecla para continuar...");
    getchar();
    getchar();
}

void GerarRelatorioNome(Lista *li) {
    char nome[30];
    printf("Digite o nome: ");
    limparBufferEntrada();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover a quebra de linha lida por fgets

    CLIENTE Pesquisar;
    int encontrado = consulta_lista_nome(li, nome, &Pesquisar);
    if (!encontrado) {
        printf("Contato não encontrado!\n");
    } else {
        printf("ID: %d\n", Pesquisar.id);
        printf("Nome: %s\n", Pesquisar.nome);
        printf("Empresa: %s\n", Pesquisar.empresa);
        printf("Telefone: %s\n", Pesquisar.telefone);
        printf("Celular: %s\n", Pesquisar.celular);
        printf("Email: %s\n\n\n", Pesquisar.email);
    }
    printf("Pressione qualquer tecla para continuar...");
    getchar();
    getchar();
}

void RemoverContato(Lista *li){
    printf("Digite o ID do contato que deseja remover: ");
    int id;
    scanf("%d", &id);
    remove_lista(li, id);
    numeroClientes = tamLista(li);
}

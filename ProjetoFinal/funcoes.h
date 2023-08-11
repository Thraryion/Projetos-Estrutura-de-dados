

typedef struct Cliente{
int id;
char nome[30];
char empresa[30];
char departamento[30];
char telefone[12];
char celular[12];
char email[60];
}CLIENTE;

typedef struct elemento* Lista;
Lista *criaLista();

void apagaLista(Lista *li);

int tamLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insere_inicio_lista(Lista *li,CLIENTE cl);
int insere_lista(Lista *li,CLIENTE cl);
int insere_final_lista(Lista *li,CLIENTE cl);

int remove_inicio_lista(Lista *li);

int remove_final_lista(Lista *li);

int remove_lista(Lista *li,int id);

int consulta_lista_pos(Lista *li, int posicao, CLIENTE *cl);

int consulta_lista_id(Lista *li, int id, CLIENTE *cl);

void menu();
void sair();

int consulta_lista_nome(Lista *li, const char *nome, CLIENTE *cl);

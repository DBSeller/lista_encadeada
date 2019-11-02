/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <malloc.h>

typedef struct {
    //código, nome, telefone, email, nota g1 e nota g2.
    int codigo, g1, g2;
    char nome[40], telefone[12], email[40];
    struct aluno * proximo;
    struct aluno * anterior;
    
} aluno;

typedef struct {
    aluno * primeiro;
    aluno * ultimo;
} lista;

void criarLista(lista * list) {
    list->primeiro = NULL;
    list->ultimo = NULL;
};

void preencherDadosAluno(aluno * a) {
    printf("Informe o nome do aluno: \n");
    scanf("%s", a->nome);
    a->proximo = NULL;
    a->anterior = NULL;
    
};

void inserirNoFinal(lista * list, aluno a) {
    aluno * aux = (aluno *) malloc(sizeof(aluno));
    *aux = a;
    if (list->ultimo == NULL) {
        list->primeiro = aux;
        list->ultimo = aux;
    } else {
        list->ultimo->proximo = (struct aluno *) aux;
        aux->anterior = (struct aluno *) list->ultimo;
        list->ultimo = aux;
    }
};

void listarTodosRegistros(lista list) {
    aluno * a = list.primeiro;
    while (a != NULL) 
    {
        printf("Nome: %s  \n", a->nome);
        a = (aluno *)a->proximo;
    };
    
};


void main()
{
    lista alunos;
    aluno a1;
    criarLista(&alunos);
    preencherDadosAluno(&a1);
    listarTodosRegistros(alunos);
    inserirNoFinal(&alunos, a1);
    listarTodosRegistros(alunos);

}

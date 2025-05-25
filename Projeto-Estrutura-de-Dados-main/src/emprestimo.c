#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emprestimo.h"

void cadastrarEmprestimo(LivroHash* livros, UsuarioHash* usuarios, Emprestimo** lista) {
    int id;
    char isbn[20];

    printf("ID do usuário: "); scanf("%d", &id); getchar();
    printf("ISBN do livro: "); fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    Usuario* u = consultarUsuario(usuarios, id);
    Livro* l = consultarLivro(livros, isbn);

    if (!u || !l) {
        printf("Usuário ou livro não encontrado.\n");
        return;
    }

    if (l->emprestado) {
        printf("Livro já está emprestado.\n");
        return;
    }

    Emprestimo* novo = malloc(sizeof(Emprestimo));
    novo->idUsuario = id;
    strcpy(novo->isbnLivro, isbn);
    novo->prox = *lista;
    *lista = novo;

    l->emprestado = 1;

    printf("Empréstimo cadastrado com sucesso!\n");
}

void listarEmprestimos(Emprestimo* lista) {
    if (!lista) {
        printf("Nenhum empréstimo registrado.\n");
        return;
    }

    printf("Lista de Empréstimos:\n");
    while (lista) {
        printf("Usuário ID: %d, Livro ISBN: %s\n", lista->idUsuario, lista->isbnLivro);
        lista = lista->prox;
    }
}

void devolverLivro(LivroHash* livros, Emprestimo** lista) {
    char isbn[20];
    printf("ISBN do livro a devolver: "); fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    Emprestimo* atual = *lista;
    Emprestimo* anterior = NULL;

    while (atual) {
        if (strcmp(atual->isbnLivro, isbn) == 0) {
            Livro* l = consultarLivro(livros, isbn);
            if (l) l->emprestado = 0;

            if (anterior)
                anterior->prox = atual->prox;
            else
                *lista = atual->prox;

            free(atual);
            printf("Livro devolvido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Empréstimo não encontrado.\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

int hashString(const char* str) {
    int hash = 0;
    while (*str) hash = (hash * 31 + *str++) % TAMANHO_TABELA;
    return hash;
}

LivroHash* criarTabelaLivros() {
    LivroHash* hash = malloc(sizeof(LivroHash));
    for (int i = 0; i < TAMANHO_TABELA; i++) hash->tabela[i] = NULL;
    return hash;
}

void cadastrarLivro(LivroHash* tabela) {
    Livro* novo = malloc(sizeof(Livro));
    printf("Título: "); fgets(novo->titulo, sizeof(novo->titulo), stdin);
    printf("Autor: "); fgets(novo->autor, sizeof(novo->autor), stdin);
    printf("ISBN: "); fgets(novo->isbn, sizeof(novo->isbn), stdin);
    novo->titulo[strcspn(novo->titulo, "\n")] = '\0';
    novo->autor[strcspn(novo->autor, "\n")] = '\0';
    novo->isbn[strcspn(novo->isbn, "\n")] = '\0';
    novo->emprestado = 0;
    novo->prox = NULL;

    int indice = hashString(novo->isbn);
    novo->prox = tabela->tabela[indice];
    tabela->tabela[indice] = novo;

    printf("Livro cadastrado com sucesso!\n");
}

Livro* consultarLivro(LivroHash* tabela, const char* isbn) {
    int indice = hashString(isbn);
    Livro* atual = tabela->tabela[indice];
    while (atual) {
        if (strcmp(atual->isbn, isbn) == 0) return atual;
        atual = atual->prox;
    }
    return NULL;
}

void salvarLivros(LivroHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "w");
    if (!f) return;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Livro* atual = tabela->tabela[i];
        while (atual) {
            fprintf(f, "%s|%s|%s|%d\n", atual->titulo, atual->autor, atual->isbn, atual->emprestado);
            atual = atual->prox;
        }
    }
    fclose(f);
}

void carregarLivros(LivroHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) return;
    char linha[300];
    while (fgets(linha, sizeof(linha), f)) {
        Livro* novo = malloc(sizeof(Livro));
        sscanf(linha, "%99[^|]|%99[^|]|%19[^|]|%d", novo->titulo, novo->autor, novo->isbn, &novo->emprestado);
        int indice = hashString(novo->isbn);
        novo->prox = tabela->tabela[indice];
        tabela->tabela[indice] = novo;
    }
    fclose(f);
}

void liberarLivros(LivroHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Livro* atual = tabela->tabela[i];
        while (atual) {
            Livro* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(tabela);
}

void verificarDisponibilidadeLivro(LivroHash* tabela, const char* isbn) {
    Livro* l = consultarLivro(tabela, isbn);
    if (l) {
        if (l->emprestado)
            printf("Livro \"%s\" está emprestado.\n", l->titulo);
        else
            printf("Livro \"%s\" está disponível.\n", l->titulo);
    } else {
        printf("Livro não encontrado.\n");
    }
}

#ifndef LIVRO_H
#define LIVRO_H

#include "tabelahash.h"

typedef struct Livro {
    char titulo[100];
    char autor[100];
    char isbn[20];
    int emprestado;
    struct Livro* prox;
} Livro;

void cadastrarLivro(LivroHash* tabela);
Livro* consultarLivro(LivroHash* tabela, const char* isbn);
void salvarLivros(LivroHash* tabela, const char* nomeArquivo);
void carregarLivros(LivroHash* tabela, const char* nomeArquivo);
void liberarLivros(LivroHash* tabela);
void verificarDisponibilidadeLivro(LivroHash* tabela, const char* isbn);

#endif

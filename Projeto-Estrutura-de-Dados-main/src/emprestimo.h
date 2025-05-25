#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "tabelahash.h"

typedef struct Emprestimo {
    int idUsuario;
    char isbnLivro[20];
    struct Emprestimo* prox;
} Emprestimo;

void cadastrarEmprestimo(LivroHash* livros, UsuarioHash* usuarios, Emprestimo** lista);
void listarEmprestimos(Emprestimo* lista);
void devolverLivro(LivroHash* livros, Emprestimo** lista);

#endif

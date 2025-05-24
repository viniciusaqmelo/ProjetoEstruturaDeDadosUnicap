#ifndef USUARIO_H
#define USUARIO_H

#include "tabelahash.h"

typedef struct Usuario {
    int id;
    char nome[100];
    struct Usuario* prox;
} Usuario;

void cadastrarUsuario(UsuarioHash* tabela);
Usuario* consultarUsuario(UsuarioHash* tabela, int id);
void carregarUsuarios(UsuarioHash* tabela, const char* nomeArquivo);
void salvarUsuarios(UsuarioHash* tabela, const char* nomeArquivo);
void liberarUsuarios(UsuarioHash* tabela);

#endif

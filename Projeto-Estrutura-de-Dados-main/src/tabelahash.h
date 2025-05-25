#ifndef TABELAHASH_H
#define TABELAHASH_H

#define TAMANHO_TABELA 100

typedef struct Livro Livro;
typedef struct Usuario Usuario;

typedef struct {
    Livro* tabela[TAMANHO_TABELA];
} LivroHash;

typedef struct {
    Usuario* tabela[TAMANHO_TABELA];
} UsuarioHash;

int hashString(const char* str);
int hashInt(int chave);

LivroHash* criarTabelaLivros();
UsuarioHash* criarTabelaUsuarios();

#endif

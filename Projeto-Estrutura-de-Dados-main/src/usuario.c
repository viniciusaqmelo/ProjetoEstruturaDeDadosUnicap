#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

int hashInt(int chave) {
    return chave % TAMANHO_TABELA;
}

UsuarioHash* criarTabelaUsuarios() {
    UsuarioHash* hash = malloc(sizeof(UsuarioHash));
    for (int i = 0; i < TAMANHO_TABELA; i++) hash->tabela[i] = NULL;
    return hash;
}

void cadastrarUsuario(UsuarioHash* tabela) {
    Usuario* novo = malloc(sizeof(Usuario));
    printf("ID: "); scanf("%d", &novo->id); getchar();
    printf("Nome: "); fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';
    novo->prox = NULL;

    int indice = hashInt(novo->id);
    novo->prox = tabela->tabela[indice];
    tabela->tabela[indice] = novo;

    printf("Usuário cadastrado com sucesso!\n");
}

Usuario* consultarUsuario(UsuarioHash* tabela, int id) {
    int indice = hashInt(id);
    Usuario* atual = tabela->tabela[indice];
    while (atual) {
        if (atual->id == id) return atual;
        atual = atual->prox;
    }
    return NULL;
}

void carregarUsuarios(UsuarioHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) return;
    char linha[150];
    while (fgets(linha, sizeof(linha), f)) {
        Usuario* novo = malloc(sizeof(Usuario));
        sscanf(linha, "%d|%99[^\n]", &novo->id, novo->nome);
        int indice = hashInt(novo->id);
        novo->prox = tabela->tabela[indice];
        tabela->tabela[indice] = novo;
    }
    fclose(f);
}

void salvarUsuarios(UsuarioHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "w");
    if (!f) return;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Usuario* atual = tabela->tabela[i];
        while (atual) {
            fprintf(f, "%d|%s\n", atual->id, atual->nome);
            atual = atual->prox;
        }
    }
    fclose(f);
}

void liberarUsuarios(UsuarioHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Usuario* atual = tabela->tabela[i];
        while (atual) {
            Usuario* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(tabela);
}

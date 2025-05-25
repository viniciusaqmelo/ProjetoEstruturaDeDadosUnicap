#include <stdlib.h>
#include "tabelahash.h"

int hashString(const char* str) {
    int hash = 0;
    while (*str)
        hash = (hash * 31 + *str++) % TAMANHO_TABELA;
    return hash;
}

int hashInt(int chave) {
    return chave % TAMANHO_TABELA;
}
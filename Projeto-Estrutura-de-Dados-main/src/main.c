#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

int main() {
    LivroHash* livros = criarTabelaLivros();
    UsuarioHash* usuarios = criarTabelaUsuarios();
    Emprestimo* emprestimos = NULL;

    carregarLivros(livros, "livros.txt");
    carregarUsuarios(usuarios, "usuarios.txt");

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Cadastrar Usuário\n");
        printf("3. Consultar Livro\n");
        printf("4. Consultar Usuário\n");
        printf("5. Listar Livros\n");
        printf("6. Fazer Empréstimo\n");
        printf("7. Listar Empréstimos\n");
        printf("8. Devolver Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar buffer

        switch (opcao) {
            case 1:
                cadastrarLivro(livros);
                break;
            case 2:
                cadastrarUsuario(usuarios);
                break;
            case 3: {
                char isbn[20];
                printf("ISBN do livro: ");
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                Livro* l = consultarLivro(livros, isbn);
                if (l)
                    printf("Título: %s | Autor: %s | Disponível: %s\n", l->titulo, l->autor, l->emprestado ? "Não" : "Sim");
                else
                    printf("Livro não encontrado.\n");
                break;
            }
            case 4: {
                int id;
                printf("ID do usuário: ");
                scanf("%d", &id);
                getchar();
                Usuario* u = consultarUsuario(usuarios, id);
                if (u)
                    printf("Nome: %s\n", u->nome);
                else
                    printf("Usuário não encontrado.\n");
                break;
            }
            case 5:
                listarLivros(livros);
                break;
            case 6:
                cadastrarEmprestimo(livros, usuarios, &emprestimos);
                break;
            case 7:
                listarEmprestimos(emprestimos);
                break;
            case 8:
                devolverLivro(livros, &emprestimos);
                break;
            case 0:
                salvarLivros(livros, "livros.txt");
                salvarUsuarios(usuarios, "usuarios.txt");
                liberarLivros(livros);
                liberarUsuarios(usuarios);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}

# 📚 Sistema de Gerenciamento de Biblioteca com Tabela Hash e Arquivos

Projeto desenvolvido para a disciplina de **Estrutura de Dados Lineares** com o objetivo de aplicar conceitos de hashing e persistência de dados via arquivos.

## 📝 Descrição do Projeto

Desenvolver um sistema que permita o cadastro, consulta e gerenciamento de livros e usuários de uma biblioteca, utilizando uma **estrutura de dados baseada em hashing (TAD Hashing)**, com acesso rápido e arquivos para armazenamento permanente.

## 🎯 Objetivos

- Utilizar o TAD tabela hash para gerenciamento rápido de livros e/ou usuários.
- Implementar arquivos para salvar os dados da biblioteca de forma persistente.
- Criar funcionalidades de cadastro, empréstimo, devolução e consulta.
- Integrar os dados da tabela hash com os arquivos.

## 🧩 Módulos Principais

### 1. Cadastro de Livros
- Campos: ISBN, título, autor, ano, editora, número de cópias.
- Utiliza o ISBN como chave na tabela hash.
- Dados salvos em `livros.dat` ou `livros.txt`.

### 2. Cadastro de Usuários
- Campos: ID do usuário, nome, e-mail, telefone.
- Usuários salvos em uma tabela hash separada.
- Persistência em `usuarios.dat` ou `usuarios.txt`.

### 3. Empréstimo de Livros
- Verifica se há cópias disponíveis.
- Atualiza arquivos e tabela hash.
- Pode registrar log da operação em `emprestimos.log`.

### 4. Devolução de Livros
- Atualiza quantidade de cópias disponíveis.
- Pode incluir data de devolução e controle de multas (opcional).

### 5. Consulta Rápida
- Buscar livros por **ISBN** ou **título**.
- Buscar usuários por **ID** ou **nome**.

### 6. Remoção e Atualização de Dados
- Marcar registros como inativos (sem apagar fisicamente).
- Atualização reflete na hash e no arquivo.

## 🗂 Estrutura de Dados

- **Tabela Hash para livros** (chave: ISBN)
- **Tabela Hash para usuários** (chave: ID)
- Arquivos:
  - `livros.dat` ou `livros.txt`
  - `usuarios.dat` ou `usuarios.txt`
  - `emprestimos.log` (opcional)

## ✨ Funcionalidades Extras (Opcional)

> Implementar essas funcionalidades pode garantir **bônus de até 1,0 ponto na nota final**.

- Relatórios: livros mais emprestados, usuários mais ativos etc.
- Histórico completo de empréstimos
- Interface com menu no terminal ou GUI simples

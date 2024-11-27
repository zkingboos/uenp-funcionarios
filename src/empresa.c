//
// Created by fcthe on 27/11/2024.
//
#include "malloc.h"
#include "stdio.h"
#include "funcionario.h"
#include "empresa.h"
#include "util.h"

Empresa *perguntar_criar_empresa() {
    char nome[MAXIMO_NOME_EMPRESA];
    printf("Digite o nome da empresa: ");
    fgetchar();
    fgets(nome, MAXIMO_NOME_EMPRESA, stdin);
    return criar_empresa(nome);
}

Empresa *criar_empresa(const char *nome) {
    Empresa *empresa = malloc(sizeof(Empresa));
    empresa->quantidade_funcionarios = 0;

    strcpy(empresa->nome, nome);
    normalizar_nome(empresa->nome);

    return empresa;
}

Funcionario *perguntar_selecionar_funcionario(Empresa empresa) {
    char nome[MAXIMO_NOME];
    printf("Digite o nome do funcionário: ");
    fgetchar();
    fgets(nome, MAXIMO_NOME, stdin);
    normalizar_nome(nome);

    Funcionario *funcionario = selecionar_funcionario(empresa, nome);
    return funcionario;
}

Funcionario *selecionar_funcionario(Empresa empresa, const char *nome) {
    for (int i = 0; i < empresa.quantidade_funcionarios; ++i) {
        Funcionario *funcionario = &empresa.funcionarios[i];
        if (strcmp(nome, funcionario->nome) == 0) {
            return funcionario;
        }
    }
    return NULL;
}

int inserir_funcionario(Empresa *empresa, Funcionario *funcionario) {
    if (empresa->quantidade_funcionarios + 1 > MAXIMO_FUNCIONARIOS) {
        puts("Não é possível adicionar mais funcionários nessa empresa.");
        return -1;
    }
    empresa->funcionarios[empresa->quantidade_funcionarios++] = *funcionario;
    return 0;
}

void remover_funcionario(Empresa *empresa, Funcionario *funcionario) {
    for (int i = 0; i < empresa->quantidade_funcionarios; ++i) {
        if (strcmp(empresa->funcionarios[i].nome, funcionario->nome) == 0) {
            for (int j = i; j < empresa->quantidade_funcionarios - 1; ++j) {
                empresa->funcionarios[j] = empresa->funcionarios[j + 1];
            }
            empresa->quantidade_funcionarios--;
            break;
        }
    }
}

void imprimir_empresa(Empresa *empresa, bool imprimir_funcionarios) {
    imprimir_separador();
    printf("Empresa: %s\n", empresa->nome);
    if (imprimir_funcionarios) {
        puts("Funcionários: ");
        imprimir_funcionarios_empresa(empresa);
    }
}

void imprimir_funcionarios_empresa(Empresa *empresa) {
    if (empresa->quantidade_funcionarios == 0) {
        puts("Nenhum funcionário registrado ainda!");
        return;
    }

    for (int i = 0; i < empresa->quantidade_funcionarios; ++i) {
        Funcionario funcionario = empresa->funcionarios[i];
        imprimir_funcionario(funcionario);
    }
}
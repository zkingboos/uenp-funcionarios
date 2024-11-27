//
// Created by fcthe on 27/11/2024.
//
#include "malloc.h"
#include "stdio.h"
#include "string.h"
#include "programa.h"
#include "util.h"

Programa *criar_programa() {
    Programa *programa = malloc(sizeof(Programa));
    programa->total_empresas = 0;
    programa->pagina = 0;

    return programa;
}

Empresa *perguntar_selecionar_empresa(Programa *programa) {
    char nome[MAXIMO_NOME_EMPRESA];
    getchar();
    printf("Selecione uma empresa para poder selecionar: ");
    fgets(&nome, MAXIMO_NOME_EMPRESA, stdin);
    normalizar_nome(nome);
    return selecionar_empresa(programa, nome);
}

Empresa *selecionar_empresa(Programa *programa, const char *nome) {
    for (int i = 0; i < programa->total_empresas; ++i) {
        Empresa *empresa = &programa->empresas[i];
        if (strcmp(nome, empresa->nome) == 0) {
            return empresa;
        }
    }
    return NULL;
}

int inserir_empresa(Programa *programa, Empresa *empresa) {
    if (programa->total_empresas + 1 > TOTAL_EMPRESAS) {
        puts("Máximo de empresas atingido.");
        return -1;
    }

    programa->empresas[programa->total_empresas++] = *empresa;
    programa->empresa_atual = empresa;
    return 0;
}

void remover_empresa(Programa *programa, Empresa *empresa) {
    if (programa->total_empresas == 0) {
        puts("Nenhuma empresa registrada ainda!");
        return;
    }

    if (programa->empresa_atual != NULL && strcmp(programa->empresa_atual->nome, empresa->nome) == 0) {
        programa->empresa_atual = NULL;
    }

    for (int i = 0; i < programa->total_empresas; ++i) {
        if (strcmp(programa->empresas[i].nome, empresa->nome) == 0) {
            for (int j = i; j < programa->total_empresas - 1; ++j) {
                programa->empresas[j] = programa->empresas[j + 1];
            }
            programa->total_empresas--;
            return;
        }
    }
}

void imprimir_programa(Programa *programa, bool imprimir_funcionarios) {
    if (programa->total_empresas == 0) {
        puts("Nenhuma empresa registrada ainda!");
        return;
    }

    for (int i = 0; i < programa->total_empresas; i++) {
        Empresa *empresa = &programa->empresas[i];
        imprimir_empresa(empresa, imprimir_funcionarios);
    }
}
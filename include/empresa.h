//
// Created by fcthe on 27/11/2024.
//

#ifndef FUNCIONARIO_EMPRESA_H
#define FUNCIONARIO_EMPRESA_H

#include "stdbool.h"
#include "funcionario.h"

#define  MAXIMO_NOME_EMPRESA 32
#define MAXIMO_FUNCIONARIOS 100

typedef struct {
    char nome[MAXIMO_NOME_EMPRESA];
    Funcionario funcionarios[MAXIMO_FUNCIONARIOS];
    int quantidade_funcionarios;
} Empresa;

Empresa *perguntar_criar_empresa();

Empresa *criar_empresa(const char *nome);

Funcionario *perguntar_selecionar_funcionario(Empresa empresa);

Funcionario *selecionar_funcionario(Empresa empresa, const char *nome);

int inserir_funcionario(Empresa *empresa, Funcionario *funcionario);

void remover_funcionario(Empresa *empresa, Funcionario *funcionario);

void imprimir_empresa(Empresa *empresa, bool imprimir_funcionarios);

void imprimir_funcionarios_empresa(Empresa *empresa);

#endif //FUNCIONARIO_EMPRESA_H

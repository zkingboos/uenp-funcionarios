//
// Created by fcthe on 27/11/2024.
//

#ifndef FUNCIONARIO_PROGRAMA_H
#define FUNCIONARIO_PROGRAMA_H

#include "empresa.h"

#define TOTAL_EMPRESAS 10

typedef struct {
    Empresa empresas[TOTAL_EMPRESAS];
    Empresa *empresa_atual;
    int total_empresas;
    int pagina;
} Programa;

Programa *criar_programa();

Empresa *perguntar_selecionar_empresa(Programa *programa);

Empresa *selecionar_empresa(Programa *programa, const char *nome);

void remover_empresa(Programa *programa, Empresa *empresa);

int inserir_empresa(Programa *programa, Empresa *empresa);

void imprimir_programa(Programa *programa, bool imprimir_funcionarios);

#endif //FUNCIONARIO_PROGRAMA_H

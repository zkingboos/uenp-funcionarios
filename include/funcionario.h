//
// Created by fcthe on 27/11/2024.
//

#ifndef FUNCIONARIO_FUNCIONARIO_H
#define FUNCIONARIO_FUNCIONARIO_H

#define MAXIMO_NOME 32
#define MAXIMO_CARGO 24

typedef struct {
    char nome[MAXIMO_NOME];
    float salario;
    char cargo[MAXIMO_CARGO];
} Funcionario;

Funcionario *perguntar_criar_funcionario();

Funcionario *criar_funcionario(const char *nome, float salario, const char *nome_cargo);

void imprimir_funcionario(Funcionario funcionario);

#endif //FUNCIONARIO_FUNCIONARIO_H
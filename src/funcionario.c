//
// Created by fcthe on 27/11/2024.
//
#include "malloc.h"
#include "util.h"
#include "funcionario.h"

Funcionario *perguntar_criar_funcionario() {
    char nome[MAXIMO_NOME], cargo[MAXIMO_CARGO];
    printf("Digite o nome do funcionário: ");
    fgets(&nome, MAXIMO_NOME, stdin);

    float salario;
    printf("Digite o salário do funcionário: ");
    scanf("%f", &salario);

    if (salario < 0) {
        puts("Salário do funcionário não pode ser menor que R$0.00");
        return NULL;
    }

    printf("Digite o cargo do funcionário: ");
    getchar();
    fgets(&cargo, MAXIMO_CARGO, stdin);

    return criar_funcionario(nome, salario, cargo);
}

Funcionario *criar_funcionario(const char *nome, float salario, const char *nome_cargo) {
    Funcionario *funcionario = malloc(sizeof(Funcionario));
    strcpy(funcionario->nome, nome);
    normalizar_nome(funcionario->nome);

    funcionario->salario = salario;

    strcpy(funcionario->cargo, nome_cargo);
    normalizar_nome(funcionario->cargo);
    return funcionario;
}

void imprimir_funcionario(Funcionario funcionario) {
    imprimir_separador();
    printf("Nome: %s\n", funcionario.nome);
    printf("Salario: R$%.2f\n", funcionario.salario);
    printf("Cargo: %s", funcionario.cargo);
    imprimir_separador();
}
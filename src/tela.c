//
// Created by fcthe on 27/11/2024.
//
#include "stdlib.h"
#include "stdio.h"
#include "tela.h"
#include "util.h"
#include "programa.h"

void _tela_listar_empresas(Programa *programa) {
    imprimir_programa(programa, false);
    perguntar_tela(programa);
}

void _tela_criar_empresa(Programa *programa) {
    Empresa *empresa = perguntar_criar_empresa();
    int resultado = inserir_empresa(programa, empresa);
    if (resultado == -1) {
        return;
    }

    perguntar_tela(programa);
}

void _tela_selecionar_empresa(Programa *programa) {
    imprimir_programa(programa, false);
    Empresa *empresa = perguntar_selecionar_empresa(programa);
    if (empresa == NULL) {
        puts("Nenhuma empresa encontrada!");
        perguntar_tela(programa);
        return;
    }

    programa->empresa_atual = empresa;
    puts("Empresa selecionada com sucesso!");
    perguntar_tela(programa);
}

void _tela_deletar_empresa(Programa *programa) {
    Empresa *empresa = perguntar_selecionar_empresa(programa);
    if (empresa == NULL) {
        puts("Nenhuma empresa encontrada!");
        perguntar_tela(programa);
        return;
    }

    remover_empresa(programa, empresa);
    perguntar_tela(programa);
}

void _tela_listar_funcionarios(Programa *programa) {
    if (programa->empresa_atual == NULL) {
        puts("Nenhuma empresa selecionada ainda...");
        perguntar_tela(programa);
        return;
    }

    imprimir_funcionarios_empresa(programa->empresa_atual);
    perguntar_tela(programa);
}

void _tela_adicionar_funcionario_empresa(Programa *programa) {
    if (programa->empresa_atual == NULL) {
        puts("Nenhuma empresa selecionada ainda...");
        perguntar_tela(programa);
        return;
    }

    getchar();
    Funcionario *funcionario = perguntar_criar_funcionario();
    if (funcionario == NULL) {
        puts("Erro ao criar funcionário...");
        perguntar_tela(programa);
        return;
    }

    int resultado = inserir_funcionario(programa->empresa_atual, funcionario);
    if (resultado == -1) {
        puts("Erro ao inserir funcionário...");
        perguntar_tela(programa);
        return;
    }

    printf("Funcionário %s adicionado com sucesso!\n", funcionario->nome);
    perguntar_tela(programa);
}

void _tela_remover_funcionario_empresa(Programa *programa) {
    Empresa *empresa = programa->empresa_atual;
    if (empresa == NULL) {
        puts("Nenhuma empresa selecionada ainda...");
        perguntar_tela(programa);
        return;
    }

    Funcionario *funcionario = perguntar_selecionar_funcionario(*empresa);
    if (funcionario == NULL) {
        puts("Funcionário não encontrado...");
        perguntar_tela(programa);
        return;
    }

    printf("Deseja realmente remover o funcionário %s? (s/n): ", funcionario->nome);
    char resposta;
    scanf("%c", &resposta);

    if (resposta != 's') {
        perguntar_tela(programa);
        return;
    }

    printf("Removendo funcionário %s...\n", funcionario->nome);
    remover_funcionario(empresa, funcionario);
    perguntar_tela(programa);
}

void tela_inicial(const Programa *programa) {
    char empresa_atual[MAXIMO_NOME_EMPRESA] = "Nenhuma empresa selecionada";
    if (programa->empresa_atual != NULL) {
        strcpy(empresa_atual, programa->empresa_atual->nome);
    }

    imprimir_separador();
    puts("Páginas: ");
    puts("EMPRESAS:");
    puts("0 - Listar empresas");
    puts("1 - Criar empresa");
    puts("2 - Selecionar empresa");
    puts("3 - Deletar empresa");
    printf("\nFUNCIONÁRIOS: %s\n", empresa_atual);
    puts("4 - Listar funcionários");
    puts("5 - Adicionar funcionário");
    puts("6 - Remover funcionário");
    puts("\n-1 - Sair");
    imprimir_separador();
}

void perguntar_tela(Programa *programa) {
    tela_inicial(programa);

    printf("Deseja ir para qual tela?: ");
    scanf("%d", &programa->pagina);

    switch (programa->pagina) {
        case -1: {
            exit(0);
            break;
        }
        case 0: {
            _tela_listar_empresas(programa);
            break;
        }
        case 1: {
            _tela_criar_empresa(programa);
            break;
        }
        case 2: {
            _tela_selecionar_empresa(programa);
            break;
        }
        case 3: {
            _tela_deletar_empresa(programa);
            break;
        }
        case 4: {
            _tela_listar_funcionarios(programa);
            break;
        }
        case 5: {
            _tela_adicionar_funcionario_empresa(programa);
            break;
        }
        case 6: {
            _tela_remover_funcionario_empresa(programa);
            break;
        }
        default: {
            puts("Página inválida, tente novamente");
            perguntar_tela(programa);
        }
    }
}
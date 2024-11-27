//
// Created by fcthe on 27/11/2024.
//
#include "stdio.h"
#include "string.h"

void imprimir_separador() {
    puts("");
    for (int i = 0; i < 50; i++) printf("-");
    puts("");
}

void normalizar_nome(char *nome) {
    for (int i = 0; i < strlen(nome); ++i) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break;
        }
    }
}

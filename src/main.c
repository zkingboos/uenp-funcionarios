#include "programa.h"
#include "tela.h"
#include "empresa.h"

int main() {
    Programa *programa = criar_programa();
    Empresa *empresa = criar_empresa("UENP");
    Funcionario *funcionario = criar_funcionario("carlos", 100, "Gerente");

    inserir_funcionario(empresa, funcionario);
    inserir_empresa(programa, empresa);
    perguntar_tela(programa);
}

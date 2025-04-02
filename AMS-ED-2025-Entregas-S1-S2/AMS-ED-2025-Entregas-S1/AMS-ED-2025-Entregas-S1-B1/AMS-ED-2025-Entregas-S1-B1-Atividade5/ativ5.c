/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade:   S1-B1-5                               */
/*             Objetivo: <<  Transformar lista ligada em Pilha   >>                 */
/*                                                                                  */
/*                                Autor: Felipe Zigon, Fernando Motta, Henry Quiles */
/*                                                                   Data:01/04/2025*/
/*----------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILHA 100

typedef struct Pedido {
    int num;
    char nome[50];
    char desc[100];
    int qtde;
    char status[3];
} Pedido;

typedef struct Pilha {
    Pedido pedidos[MAX_PILHA];
    int topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = -1;
    return pilha;
}

void push(Pilha* pilha, int num, char *nome, char *desc, int qtde, char *status) {
    if (pilha->topo == MAX_PILHA - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    pilha->topo++;
    pilha->pedidos[pilha->topo].num = num;
    strcpy(pilha->pedidos[pilha->topo].nome, nome);
    strcpy(pilha->pedidos[pilha->topo].desc, desc);
    pilha->pedidos[pilha->topo].qtde = qtde;
    strcpy(pilha->pedidos[pilha->topo].status, status);
}

void pop(Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return;
    }
    pilha->topo--;
    printf("Pedido removido do topo\n");
}

void obterPedido(Pilha* pilha, int num) {
    for (int i = pilha->topo; i >= 0; i--) {
        if (pilha->pedidos[i].num == num) {
            printf("------------\n Pedido: %d\n Nome: %s\n Desc: %s\n Quantidade: %d\n Status: %s\n", 
                   pilha->pedidos[i].num, pilha->pedidos[i].nome, pilha->pedidos[i].desc, 
                   pilha->pedidos[i].qtde, pilha->pedidos[i].status);
            return;
        }
    }
    printf("Pedido não encontrado\n");
}

void atualizarStatus(Pilha* pilha, int num) {
    for (int i = pilha->topo; i >= 0; i--) {
        if (pilha->pedidos[i].num == num) {
            char novoStatus[3];
            printf("Novo status: ");
            scanf("%s", novoStatus);
            strcpy(pilha->pedidos[i].status, novoStatus);
            printf("Status atualizado com sucesso!\n");
            return;
        }
    }
    printf("Pedido não encontrado\n");
}

void limparPilha(Pilha* pilha) {
    pilha->topo = -1;
    printf("Pilha limpa\n");
}

void exibirMenu() {
    printf("\n 1. Inserir pedido \n 2. Obter pedido \n 3. Atualizar status \n 4. Remover pedido \n 5. Limpar pilha \n 6. Sair \n");
}

int main() {
    Pilha* pilha = criarPilha();
    int opcao, num, qtde;
    char nome[50], desc[100], status[3];

    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Numero do pedido: ");
                scanf("%d", &num);
                getchar();

                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Descricao do prato: ");
                fgets(desc, sizeof(desc), stdin);
                desc[strcspn(desc, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &qtde);
                getchar();

                printf("PE = pendente  EM = em preparo  PO = pronto  EN = entregue \nstatus do pedido: ");
                scanf("%2s", status);

                push(pilha, num, nome, desc, qtde, status);
                break;

            case 2:
                printf("Numero do pedido: ");
                scanf("%d", &num);
                obterPedido(pilha, num);
                break;

            case 3:
                printf("Numero do pedido: ");
                scanf("%d", &num);
                atualizarStatus(pilha, num);
                break;

            case 4:
                pop(pilha);
                break;

            case 5:
                limparPilha(pilha);
                break;

            case 6:
                printf("Saindo...\n");
                limparPilha(pilha);
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 6);

    return 0;
}

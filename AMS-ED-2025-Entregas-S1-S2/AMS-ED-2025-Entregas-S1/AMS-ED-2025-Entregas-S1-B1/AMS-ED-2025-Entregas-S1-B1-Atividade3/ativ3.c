#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido{
    int num;
    char nome[50];
    char desc[100];
    int qtde;
    char status[3];
    struct Pedido *proximo;
}Pedido;

Pedido *criarLista(){
    return NULL;    
}

Pedido *inserirPedido(Pedido *lista, int num, char *nome, char *desc, int qtde, char *status){
    Pedido *novo = malloc(sizeof(Pedido)); 
    if (!novo){
        printf("erro na memória\n");
        return lista;
    }
    novo->num = num;
    strcpy(novo->nome, nome);
    strcpy(novo->desc, desc);
    novo->qtde = qtde;
    strcpy(novo->status, status);
    novo->proximo = lista; 
    return novo;

}

void obterPedido(Pedido *lista, int num){
    Pedido *atual = lista;
    while(atual){
        if(atual->num == num){
            printf("------------\n Pedido: %d\n Nome: %s\n Desc: %s\n Quantidade: %d\n Status: %s\n", atual->num, 
            atual->nome, atual->desc, atual->qtde, atual->status);
            return;
        }
        atual = atual->proximo;
    }
    printf("Pedido nao encontrado\n");
}

void atualizarStatus(Pedido *lista, int num){
    Pedido *atual = lista;
    char *nstatus = malloc(sizeof(char) * 3);
    if (!nstatus){
        printf("Erro na memoria");
        return;
    }

    while(atual){
        if(atual->num == num){
            printf("Novo status: ");
            scanf("%s", nstatus);
            getchar();
            strcpy(atual->status, nstatus);
            return;
        }
        atual = atual->proximo;
    }
    printf("Pedido nao encontrado\n");
}


Pedido *deletarPedido(Pedido *lista, int num){
    Pedido *atual= lista, *anterior = NULL;
    while(atual){
        if(atual->num == num){
            if(anterior){
                anterior->proximo = atual->proximo;
            }
            else{
                lista = atual->proximo;
            }
            free(atual);
            printf("Pedido %d removido\n", num);
            return lista;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Pedido nao encontrado\n");
    return lista;
}

void limparLista(Pedido **lista){
    Pedido *atual = *lista, *prox;

    if(lista == NULL){
        printf("Lista ja esta vazia");
        return;
    }

    while(atual){
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    printf("Lista limpa");
    return;
}

int main(){
    Pedido *lista = criarLista();
    int opcao, num, qtde;
    char nome[50], desc[100], status[3];

    do{
        printf("\n 1. Inserir pedido \n 2. Obter pedido \n 3. Atualizar status \n 4. Deletar pedido \n 5. Sair \n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
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
                
                lista = inserirPedido(lista, num, nome, desc, qtde, status);
                
                break;

            case 2:
                printf("Numero do pedido: ");
                scanf("%d", &num);
                obterPedido(lista, num);
                break;
            case 3:
                printf("Numero do pedido: ");
                scanf("%d", &num);
                atualizarStatus(lista, num);
                break;
            case 4:
                printf("Numero do pedido: ");
                scanf("%d", &num);
                lista = deletarPedido(lista, num);
                break;

            case 5: 
                printf("Saindo...\n");
                limparLista(&lista);
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while(opcao != 5);
    return 0;
}
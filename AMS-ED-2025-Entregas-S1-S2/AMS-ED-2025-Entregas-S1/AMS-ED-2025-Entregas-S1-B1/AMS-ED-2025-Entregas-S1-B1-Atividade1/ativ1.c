#include <stdio.h>

int descon, precoFinal;
int *descPtr = &descon;
int *finalPtr = &precoFinal;

void AplicarDesconto(int preco, int vdesc){
    descon = (preco * vdesc)/100;
    precoFinal = preco - descon;
}

int main()
{
    int precoProduto = 200;
    int *precoPtr = &precoProduto;

    int valorDesconto;
    printf("Digite a porcentagem do desconto: ");
    scanf("%d", &valorDesconto);
    int *valordescPtr = &valorDesconto;

    AplicarDesconto(*precoPtr, *valordescPtr);

    printf("Valor Original: %d\n ", *precoPtr);
    printf("Desconto: %d\n", *descPtr);
    printf("Preco final: %d\n", *finalPtr);
    
    return 0;
}
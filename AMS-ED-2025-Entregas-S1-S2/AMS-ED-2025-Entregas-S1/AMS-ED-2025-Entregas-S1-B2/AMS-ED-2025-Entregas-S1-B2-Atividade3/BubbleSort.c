/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: S1-B2-Atividade 3                       */
/*             Objetivo: <<  Comparação bubbleSort e insertionSort>>                */
/*                                                                                  */
/*                 Autor: Felipe Zigon, Fernando Motta, Henry Quiles, Yan Dall'Acqua*/
/*                                                                   Data:13/05/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>

int bubbleSort(int array[], int tamanho){
    int ciclos = 0;
    
    for (int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - i - 1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                ciclos++;
            }
        }
    }
    return ciclos;
}

void imprimir(int array[], int tamanho){
    for(int i = 0; i<tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int tamanho;
    int ciclos;

    printf("Quantidade de elementos do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os %d elementos: \n", tamanho);
    for (int i = 0; i < tamanho; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nArray original: ");
    imprimir(array, tamanho);

    ciclos = bubbleSort(array, tamanho);

    printf("Array em ordem ascendente: ");
    imprimir(array, tamanho);

    printf("Quantidade de ciclos: %d", ciclos);

    return 0;
}


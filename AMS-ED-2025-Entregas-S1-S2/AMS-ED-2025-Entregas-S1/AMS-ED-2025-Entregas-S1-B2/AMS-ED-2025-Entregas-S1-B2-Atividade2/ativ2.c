/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: S1-B2-Atividade 2                       */
/*             Objetivo: <<  Mostrar array em forma ascendente com BubbleSort>>     */
/*                                                                                  */
/*                                  Autor: Felipe Garcez Zigon                      */
/*                                                                   Data:06/05/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

void bubbleSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {

                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void imprimir(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;

    printf("Quantidade elementos do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os %d elementos:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array original: ");
    imprimir(array, tamanho);

    bubbleSort(array, tamanho);
    printf("Array ordenado em ordem crescente: ");
    imprimir(array, tamanho);

    return 0;
}

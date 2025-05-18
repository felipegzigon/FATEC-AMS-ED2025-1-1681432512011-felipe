/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: S1-B2-Atividade 3                       */
/*             Objetivo: <<  Comparação bubbleSort e insertionSort>>                */
/*                                                                                  */
/*                 Autor: Felipe Zigon, Fernando Motta, Henry Quiles, Yan Dall'Acqua*/
/*                                                                   Data:18/05/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>

int insertSort(int array[], int tamanho){
    int ciclos = 0;

    for(int i = 1; i < tamanho; i++){
        int temp = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
            ciclos++;
        }

        if(j + 1 != i){
            array[j + 1] = temp;
            ciclos++;
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

    ciclos = insertSort(array, tamanho);

    printf("Array em ordem ascendente: ");
    imprimir(array, tamanho);

    printf("Quantidade de ciclos: %d", ciclos);

    return 0;
}

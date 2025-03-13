#include <stdio.h>
#include <string.h>

void ordenarCandidatos(float NF[], int indices[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (NF[indices[i]] < NF[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
}

float calcIntermed(float fase[], int nNotas){
    float maior = -1, menor = 11;
    float soma = 0;
    int idMaior = -1, idMenor = -1;

    for (int j = 0; j < nNotas; j++){
        if(fase[j] > maior){
            maior = fase[j];
            idMaior = j;
        }

        if(fase[j] < menor){
            menor = fase[j];
            idMenor = j;
        }
        }

    for(int j = 0; j < nNotas; j++){
        if(j != idMaior && j != idMenor){
            soma += fase[j];
        }
    }    
    return soma;
}

int main(){

    char Nomes[50][45];
    
    float PE[50][4];
    float AC[50][5];
    float PP[50][10];
    float EB[50][3];

    float PEintermds[50];
    float ACintermds[50];
    float PPintermds[50];
    float EBintermds[50];

    float NF[50];
    int i, total = 0, iPE, iAC, iPP, iEB;

    for(i = 0; i < 50; i++){
        printf("Nome do candidato(digite x para finalizar): ");
        scanf(" %[^\n]s", Nomes[i]);
        if (strcmp(Nomes[i], "x") == 0){
            break;
        }

        PEintermds[i] = 0;
        
        for (iPE = 0; iPE < 4; iPE++){
            do {
                printf("PE Nota %d: ", iPE+1);
                scanf("%f", &PE[i][iPE]);
            
                if (PE[i][iPE] < 0.0 || PE[i][iPE] > 10.0){
                    printf("valor invalido. Digite uma nota entre 10.0 e 0.0 \n");
                }


            } while(PE[i][iPE] < 0.0 || PE[i][iPE] > 10.0);

        }
        PEintermds[i] = calcIntermed(PE[i], 4);

        ACintermds[i] = 0;
        
        for (iAC = 0; iAC < 5; iAC++){
            do {
                printf("AC Nota %d: ", iAC+1);
                scanf("%f", &AC[i][iAC]);
            
                if (AC[i][iAC] < 0.0 || AC[i][iAC] > 10.0){
                    printf("valor invalido. Digite uma nota entre 10.0 e 0.0 \n");
                }


            } while(AC[i][iAC] < 0.0 || AC[i][iAC] > 10.0);

        }
        ACintermds[i] = calcIntermed(AC[i], 5);

        PPintermds[i] = 0;
        
        for (iPP = 0; iPP < 10; iPP++){
            do {
                printf("PP Nota %d: ", iPP+1);
                scanf("%f", &PP[i][iPP]);
            
                if (PP[i][iPP] < 0.0 || PP[i][iPP] > 10.0){
                    printf("valor invalido. Digite uma nota entre 10.0 e 0.0 \n");
                }


            } while(PP[i][iPP] < 0.0 || PP[i][iPP] > 10.0);

        }
        PPintermds[i] = calcIntermed(PP[i], 10);

        EBintermds[i] = 0;
        
        for (iEB = 0; iEB < 3; iEB++){
            do {
                printf("EB Nota %d: ", iEB+1);
                scanf("%f", &EB[i][iEB]);
            
                if (EB[i][iEB] < 0.0 || EB[i][iEB] > 10.0){
                    printf("valor invalido. Digite uma nota entre 10.0 e 0.0 \n");
                }


            } while(EB[i][iEB] < 0.0 || EB[i][iEB] > 10.0);

        }
        EBintermds[i] = calcIntermed(EB[i], 3);

        total++;

        NF[i] = ((PEintermds[i] * 0.3) + (ACintermds[i] * 0.1) + (PPintermds[i] * 0.4) + (EBintermds[i] * 0.2));
    }
    int indices[50];
    for(i = 0; i < total; i++){
        indices[i] = i;
    }


    ordenarCandidatos(NF, indices, total);
    printf("\nTop 5 Candidatos:\n");
    for (i = 0; i < (total < 5 ? total : 5); i++) {
        int idx = indices[i];
        printf("%d. %s - Nota Final: %.2f\n", i + 1, Nomes[idx], NF[idx]);
    }

    return 0;
}
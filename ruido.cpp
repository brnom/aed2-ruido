#include <iostream>
using namespace std;

int main(){


    char file_name[100], *seq, *ruido;
    int i, tSeq, tRuido;
    FILE *entrada;

    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL){
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(entrada, "%d %d ", &tSeq, &tRuido);

    seq = (char *)malloc(tSeq * sizeof(char));
    ruido = (char *)malloc(tRuido * sizeof(char));
    
    for (i = 0; i < tSeq; i++){    
        fscanf(entrada, "%c", &seq[i]);
    }

    getc(entrada);
    getc(entrada);


    for (i = 0; i < tRuido; i++){    
        fscanf(entrada, "%c", &ruido[i]);
    }
    fclose(entrada);

    // parte braba segue abaixo ksks
    for(i=0; i<tSeq; i++){
        int c=0;
        while(seq[i+c]==ruido[c] && c<tRuido){
            if(c==tRuido-1)
                cout<<i<<endl;
            c++;
        }
    }

    free(seq);
    free(ruido);
    return 0;    
}
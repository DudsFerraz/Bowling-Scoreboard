#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append(int vet[], int *len, int value){
    vet[(*len)++]=value;
    return value;
}

int main(){
    char stringNumbers[100];
    int vetNumbers[100], number, lenVetNumbers=0;

    printf("String:");
    fgets(stringNumbers,100,stdin);
    stringNumbers[strlen(stringNumbers)-1]='\0';

    char *token = strtok(stringNumbers," ");
    while(token != NULL){
        printf("%s\n",token);
        number = atoi(token);
        append(vetNumbers,&lenVetNumbers,number);
        token = strtok(NULL," ");
    }

    for(int i=0;i<lenVetNumbers;i++){
        printf("%d ",vetNumbers[i]);
    }
    printf("\n\n");

    return 0;
}
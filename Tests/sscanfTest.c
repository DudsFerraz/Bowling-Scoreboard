#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char stringNumbers[100];
    int vetNumbers[100], lenVetNumbers=0, pos=0, incremento;

    printf("String:");
    fgets(stringNumbers,100,stdin);
    stringNumbers[strlen(stringNumbers)-1]='\0';

    while((sscanf(stringNumbers+pos, "%d%n", &vetNumbers[lenVetNumbers], &incremento))==1){
        pos+=incremento;
        lenVetNumbers++;
    }

    for(int i=0;i<lenVetNumbers;i++){
        printf("%d ",vetNumbers[i]);
    }
    printf("\n\n");

    return 0;
}
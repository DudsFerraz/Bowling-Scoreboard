#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getPoints(char *pontuacoes){
    fgets(pontuacoes,50,stdin);
    pontuacoes[strlen(pontuacoes)-1]='\0';
}

int append(int vet[],int *len,int value){
    vet[(*len)++]=value;
    return value;
}

int checaBonus(int vetorPontos[],int i,int *flagBonusStrike,int *flagBonusSpare,int jogada){
    if(vetorPontos[i]==10){
        *flagBonusStrike=1;
        return 1;
    }
    if(jogada==2 && vetorPontos[i-1]+vetorPontos[i]==10){
        *flagBonusSpare=1;
        return 1;
    }
    return 0;
}

void preparaSaida(int vetorPontos[],int *lenVetorPontos, int vetorSaida[],int *lenVetorSaida){
    int jogada =1, frames=1;;

    for(int i=0;i<*lenVetorPontos;i++){
        if(jogada==2 && vetorPontos[i-1]+vetorPontos[i]==10 && vetorPontos[i-1]!=10){
            append(vetorSaida,lenVetorSaida,12);
        }else{
            append(vetorSaida,lenVetorSaida,vetorPontos[i]);
        }
        if(vetorPontos[i]==10 && frames<10){
            append(vetorSaida,lenVetorSaida,11);
        }
        
        jogada++;
        if(jogada>2 || vetorPontos[i]==10 && frames<10){
            jogada=1;
            frames++;
        }
    }
}

void marcaPontos(int vetorPontos[],int *lenVetorPontos,int vetorPontosFrames[],int *lenVetorPontosFrames){
    int jogada=1, frames=1, pontosFrame=0, flagBonusStrike=0, flagBonusSpare=0;

    for(int i=0;i<*lenVetorPontos;i++){
        checaBonus(vetorPontos,i,&flagBonusStrike,&flagBonusSpare,jogada);

        if(flagBonusStrike==1 && frames<10){
            pontosFrame+=vetorPontos[i]+vetorPontos[i+1]+vetorPontos[i+2];
            flagBonusStrike=0;
        }else if(flagBonusSpare==1 && frames<10){
            pontosFrame+=vetorPontos[i]+vetorPontos[i+1];                
            flagBonusSpare=0;
        }else{
            pontosFrame+=vetorPontos[i];
        }

        jogada++;
        if(frames==10){
            pontosFrame=(vetorPontos[i]+vetorPontos[i+1]);
            if(i+2<*lenVetorPontos){
                pontosFrame+=vetorPontos[i+2];
            }    
            append(vetorPontosFrames,lenVetorPontosFrames,pontosFrame);
            break;
        }else if(jogada>2 || vetorPontos[i]==10 && frames<10){
            append(vetorPontosFrames,lenVetorPontosFrames,pontosFrame);
            pontosFrame=0;
            jogada=1;
            frames++;
        }
    }
}

int somaPontos(int vetorPontosFrames[],int lenVetorPontosFrames){
    int pontos=0;
    for(int i=0;i<lenVetorPontosFrames;i++){
        pontos+=vetorPontosFrames[i];
    }
    return pontos;
}

void mostraSaidaFormatada(int vetorSaida[],int lenVetorSaida){
    printf("\n\n");
    int counter=0;
    for(int i=0;i<lenVetorSaida;i++){
        if(vetorSaida[i]==10){
            printf("X ");
        }else if(vetorSaida[i]==11){
            printf("_ ");
        }else if(vetorSaida[i]==12){
            printf("/ ");
        }else{
            printf("%d ",vetorSaida[i]);
        }
        counter++;
        if(counter==2 && i<=18){
            printf("| ");
            counter=0;
        }
    }
    printf("\n");
}

int main(){
    int vetorPontos[30], lenVetorPontos=0, pos=0;
    int vetorSaida[30], lenVetorSaida=0;
    int vetorPontosFrames[10], lenVetorPontosFrames=0;
    char pontuacoes[50];
    int pontos, incremento;

    printf("Pontuacoes:");
    getPoints(pontuacoes);
    while((sscanf(pontuacoes+pos, "%d%n", &vetorPontos[lenVetorPontos], &incremento))==1){
        lenVetorPontos++;
        pos+=incremento;
    }

    preparaSaida(vetorPontos,&lenVetorPontos,vetorSaida,&lenVetorSaida);
    marcaPontos(vetorPontos,&lenVetorPontos,vetorPontosFrames,&lenVetorPontosFrames);
    pontos = somaPontos(vetorPontosFrames,lenVetorPontosFrames);

    mostraSaidaFormatada(vetorSaida,lenVetorSaida);
    printf("%d",pontos);

    return 0;
}
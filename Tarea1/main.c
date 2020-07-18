#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WINDOWS
	#define Limpiar_Pantalla system("cls");
#else
	#define Limpiar_Pantalla system("clear");
#endif

int entregado, entregado2;

int menu();
char Caracter_Matriz();
char Caracter_Usuario();
void Diagonal1(char caracter_matriz, char caracter_usuario, int entregado);
void Horizontal_Inf(char caracter_matriz, char caracter_usuario, int entregado);
void Diagonal2(char caracter_matriz, char caracter_usuario, int entregado, int entregado2);
void Horizontal_Sup(char caracter_matriz, char caracter_usuario, int entregado);
void Imprime_Matriz(char caracter_matriz, char caracter_usuario, int sentido);



int main(){
    int sentido = menu();
    char matriz = Caracter_Matriz();
    char usuario = Caracter_Usuario();
    Imprime_Matriz(matriz, usuario, sentido);
}


int  menu(){
    int respuesta;
    printf("Seleccione el sentido\n");
    printf("   1. Horario\n");
    printf("   2. Antihorario\n");
    
    while(1>0){
        scanf(" %i", &respuesta);
        if(respuesta==1 || respuesta==2){
            break;
        }
    }
    Limpiar_Pantalla;
    return respuesta;
}


char Caracter_Matriz(){
    char caracter_matriz;
    printf("Ingresa el caracter para dibujar la matriz\n");
    scanf(" %c", &caracter_matriz);
    return caracter_matriz;
}

char Caracter_Usuario(){
    char caracter_usuario;
    printf("Ingresa el caracter que va a viajar\n");
    scanf(" %c", &caracter_usuario);
    return caracter_usuario;
}

void Diagonal1(char caracter_matriz, char caracter_usuario, int contador){
    char matriz[20][20];
    for (int i =0; i<20; i++){
        for(int j =0; j<20; j++){
            if(i == contador && j == contador){
                matriz[i][j]= caracter_usuario;
            }
            else{
                matriz[i][j] = caracter_matriz;
            }
        }
    }
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    sleep(1);
    Limpiar_Pantalla;
    contador++;
}

void Horizontal_Inf(char caracter_matriz, char caracter_usuario, int contador){
    char matriz[20][20];
    for (int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(i==19 && j==contador){
                matriz[i][j]=caracter_usuario;
            }
            else{
                matriz[i][j]=caracter_matriz;
            }
        }
    }
        for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    sleep(1);
    Limpiar_Pantalla;
    contador--;
}

void Diagonal2(char caracter_matriz, char caracter_usuario, int contador, int contador2){
    char matriz[20][20];
    for (int i =0; i<20; i++){
        for(int j =0; j<20; j++){
            if(i == contador2 && j == contador){
                matriz[i][j]= caracter_usuario;
            }
            else{
                matriz[i][j] = caracter_matriz;
            }
        }
    }
    
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    sleep(1);
    Limpiar_Pantalla;
    contador++;
    contador2--;
}

void Horizontal_Sup(char caracter_matriz, char caracter_usuario, int contador){
    char matriz[20][20];
    for (int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(i==0 && j==contador){
                matriz[i][j]=caracter_usuario;
            }
            else{
                matriz[i][j]=caracter_matriz;
            }
        }
    }
        for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    sleep(1);
    Limpiar_Pantalla;
    contador--;
}

void Imprime_Matriz(char caracter_matriz, char caracter_usuario, int sentido){
    Limpiar_Pantalla;
    while(1>0){
    int contador=0;
    do{ //---MOVIMIENTO 1---
        if(sentido==2)
           entregado=19-contador;
        else
            entregado=contador;
        Diagonal1(caracter_matriz, caracter_usuario, entregado);
        contador++;
    }while(contador<20);
    contador = 18;
    do{ //---MOVIMIENTO 2---
        if(sentido==2){
           entregado=19-contador;
           Horizontal_Sup(caracter_matriz, caracter_usuario, entregado);
        }
        else{
            entregado=contador;
            Horizontal_Inf(caracter_matriz, caracter_usuario, entregado);
        }
        contador--;
    }while(contador>=0);
    int contador2=18;
    contador=1;
    do{ //---MOVIMIENTO 3---
        if(sentido==2){
           entregado=19-contador;
           entregado2=19-contador2;
        }
        else{
            entregado=contador;
            entregado2=contador2;
        }
        Diagonal2(caracter_matriz, caracter_usuario, entregado, entregado2);
        contador++;
        contador2--;
    }while(contador<20);
    contador=18;
    do{ //---MOVIMIENTO 4---
        if(sentido==2){
           entregado=19-contador;
           Horizontal_Inf(caracter_matriz, caracter_usuario, entregado);
        }
        else{
            entregado=contador;
            Horizontal_Sup(caracter_matriz, caracter_usuario, entregado);
        }
        contador--;
    }while(contador>=0);
}
}
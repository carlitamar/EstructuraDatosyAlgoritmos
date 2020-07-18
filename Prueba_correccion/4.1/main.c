#include <stdio.h>
void ordenarnumeros(int numero[], int larg);
int busquedaTernaria(int arreglo[], int min, int max, int buscado);

int main(void){
    
    int largo;
    
    printf("Introduzca la cantidad de elementos del arreglo \n");
    scanf(" %i", &largo);
    
    int arreglo[largo];

    for(int i=0; i<largo; i++){
        int numero;
        printf("introduzca el numero:\n ");
        scanf(" %i", &numero);
        arreglo[i]=numero;
        printf("\n");
    }
    
    ordenarnumeros(arreglo, largo);
    
         for(int k=0; k<largo; k++){
        
        printf("%d ", arreglo[k]);
     
    }
    printf("\n");
   printf("Que numero buscas?\n");
    int buscado;
    scanf(" %i",&buscado);
    int encontrado=busquedaTernaria(arreglo,0,largo,buscado);
    
    while (encontrado == -1){
    printf("el numero no se encuentra en el arreglo, ingrese otro numero:\n");
    scanf("%i", &buscado);
    encontrado=busquedaTernaria(arreglo,0,largo,buscado);
    }
    
    printf("el numero esta en la posicion: %i", encontrado+1);
    
}

void ordenarnumeros(int numero[], int larg){
    int aux;
    for(int i=0; i<larg; i++){

        for(int j=i+1; j<larg; j++){

            if(numero[i] > numero[j]){

                aux = numero[i];
                numero[i] = numero[j];
                numero[j] = aux;

            }
        }
    }


}

int busquedaTernaria(int arreglo[], int min, int max, int buscado){

    if(max>0){
        
        int mid1 = min + (max - min)/3 ;
        int mid2 = mid1 + (max - min)/3;
        
        if(arreglo[mid1]==buscado)
        return mid1;
        
         if(arreglo[mid2]==buscado)
        return mid2;
        
        if (buscado < arreglo[mid1])
        return busquedaTernaria(arreglo,0,mid1,buscado);
        
        if (buscado > arreglo[mid2])
        return busquedaTernaria(arreglo,mid2+1,max,buscado);
        
        return busquedaTernaria(arreglo,mid1,mid2,buscado);
    }
    else 
    return -1;
      
}
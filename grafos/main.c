#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  //lectura desde archivo 
  printf("Leyendo archivo...\n");
  FILE *grafoArchivo;
  char ch, buffer[32];
  int num[100], elementos[100], i = 0, cantidadElementos = 0, x = 1;
  
  
	grafoArchivo = fopen ("red.txt", "r"); 

  while(1){
    ch = fgetc(grafoArchivo);
    
    if(ch == EOF){
      break;
    }
    
    else if(ch == ' ' || ch == '\n'){
      num[cantidadElementos] = atoi(buffer);
      
      cantidadElementos++;
      
      bzero(buffer, 32);
      
      i = 0;
      
      continue;
    }
    else{
      buffer[i] = ch;
      i++;
    }
  }
  
  printf("Archivo leido.\n");
  /*
  for(int j = 0; j < cantidadElementos; j++){
     printf("%i, ", num[j]);
  }
  */
  
  //printf("\n");
  
  //printf("Cantidad de Elementos: %i", cantidadElementos);
  
  int r = 0;
  
  for (int j = 0; j != cantidadElementos; j++){
    for (int k = 0; k != j; k++){ 
      if((j != k) && (num[k] == num[j])){
        //printf("Un duplicado k: %i j: %i\n", k, j);
        r++;
        goto endoffor;
      }
    }
    endoffor: printf(" ");
  }
  
  //printf("\nR: %i\n", r);
  
  int cantidadNodos;
  cantidadNodos = cantidadElementos - r;
  
  //printf("Cantidad de Nodos: %i\n", cantidadNodos);
  printf("\n");
  
	printf("--------------\n");
	printf("\n");
	
	printf("Cargando elementos en la ED (grafo)...\n");
	int grafo[cantidadNodos+1][cantidadNodos+1];
	int a = 0, b = 1;
  
  for(int j = 1; j <= cantidadNodos; j++){
    for(int k = 1; k <= cantidadNodos; k++){
        grafo[j][k] = 0;
    }
  }
  /*
  for(int j = 1; j <= cantidadNodos; j++){
    for(int k = 1; k <= cantidadNodos; k++){
      if(j==num[a] && k==num[b]){
        grafo[j][k] = 1;
        grafo[k][j] = 1; //se elimina si fuera direccional
        a = a + 2;
        b = b + 2;
      }
      
    }
  }
  */
  for(int j = 1; j <= (cantidadElementos/2); j++){
    grafo[num[a]][num[b]] = 1;
    grafo[num[b]][num[a]] = 1; //se elimina si fuera direccional
    a = a + 2;
    b = b + 2;
  }
  
  printf("Elementos cargados en la ED (grafo).\n");
  printf("\n");
  printf("--------------\n");
  printf("\n");
  
  //despliege de grafo
  printf("Despliege de grafo...\n");
  
  if(cantidadNodos == 0){
    printf("No hay elementos para crear un grafo.\n");
  }
  else{
    printf("  |");
    for(int j = 1; j <= cantidadNodos; j++){
      printf("%i ", j);
    }
    printf("\n");
    printf("  ");
    for(int j = 1; j <= cantidadNodos; j++){
      printf("--");
    }
    printf("\n");
    
    
    
    for(int j = 1; j <= cantidadNodos; j++){
      printf("%i |", j);
      for(int k = 1; k <= cantidadNodos; k++){
        printf("%i ", grafo[j][k]);
      }
      printf("\n");
    }
  }
  printf("\n");
  printf("--------------\n");
  
  int respuesta;
  do{
    printf("Seleccione su opción\n");
    printf("1. Conocer los vecinos de cierto nodo.\n"); 
    printf("2. Conocer el nodo más popular.\n");
    printf("3. Evacuar\n");
    printf("Respuesta:\n");
    
    scanf(" %i", &respuesta);

    switch(respuesta) {
        case 1:
            printf("\nEl grafo tiene %i nodos. ¿De qué nodo desea conocer los vecinos?\n", cantidadNodos);
            int nodo;
            printf("Respuesta:\n");
            scanf(" %i", &nodo);
            
            printf("Los vecinos del nodo %i son: \n", nodo);
            for(int j = nodo; j <= nodo; j++){
              for(int k = 1; k <= cantidadNodos; k++){
                if((j!=k) && (grafo[j][k]==1)){
                  printf(" -el nodo %i\n", k);
                }
              }
            }
            printf("\n\n");
            
            break;
        case 2:
            printf("\nEl/Los nodo más popular(es) es/son: \n");
            int popular = 0;
            int temp = 0;
            int tempPopular = 0;
            for(int j = 1; j < cantidadNodos; j++){
              temp = 0;
              for(int k = 1; k <= cantidadNodos; k++){
                if(grafo[j][k]==1){
                  temp++;
                }
              }
              
              if(temp > tempPopular){
                tempPopular = temp;
                popular = j;
              }
            }
            
            //////
            
          
            int temp2 = 0;
            for(int j = 1; j < cantidadNodos; j++){
              temp2 = 0;
              for(int k = 1; k <= cantidadNodos; k++){
                if(grafo[j][k]==1){
                  temp2++;
                }
              }
              
              if(temp2 == tempPopular){
                printf(" -el nodo %i, con %i enlaces.\n", j, temp2);
              }
            }
            
            printf("\n");
            
            break;
        case 3:
            break;
        default:
            printf("No escogiste ninguna opción válida\n");
            break;
    }
  }while (respuesta!=3);

}

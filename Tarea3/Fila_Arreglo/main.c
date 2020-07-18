#include<stdio.h>
#include<stdlib.h>
#include"fila_a.h"

void main()
{
    int ch;
    int isempty;
    while(1)  //loop infinito, termina cuando la elección es 5
    {
        printf("\nElija una de las opciones:\n");
        printf("1.Queue\n2.Dequeque\n3.Peek\n4.IsEmpty\n5.Evacuar\n");
        printf("Elija su elección(1-5):\n");
        scanf("%d",&ch);
      
        switch(ch)
        {
            case 1: queue();
                    break;
            case 2: dequeue();
                    break;
            case 3: peek_q();
                    break;
            case 4: isempty=isempty_q();
                    if(isempty==1){
                      printf("La fila está vacía:\n");
                    }
                    else{ //isempty==0
                      printf("La fila no está vacía:\n");
                    }
                    break;
            case 5: exit(0);
            default: printf("\nElección invalida, elija del 1-5.");
        }
    }
}
 

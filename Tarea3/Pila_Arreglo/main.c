#include<stdio.h>
#include<stdlib.h>
#include"pila_a.h"
 
void main()
{
    int ch;
    int isempty;
    while(1)  //loop infinito, termina cuando la elección es 5
    {
        printf("\nElija una de las opciones:\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.Evacuar\n");
        printf("Elija su elección(1-5):\n");
        scanf("%d",&ch);
      
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek_s();
                    break;
            case 4: isempty=isempty_s();
                    if(isempty==1){
                      printf("La pila está vacía:\n");
                    }
                    else{ //isempty==0
                      printf("La pila no está vacía:\n");
                    }
                    break;
            case 5: exit(0);
            default: printf("\nElección invalida, elija del 1-5.");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

//Diego Opazo

//cambiar al usar en unix, no me funciono el ifdef :(
#define Limpiar_Pantalla system("cls");

typedef struct node{
    int n;
    struct node* next;
    int cambio;
    //cambio=-1 si es el ultimo de alta prioridad, 1 si es el primero de baja prioridad, 0 en otro caso
}node;

void QUEUE(int n);
void QUEUE_P(int n);
void DEQUEUE(void);
void mostrarLista(node* first);
void menu();

node* first = NULL;

int main() {
    menu();
}

void menu(){
    int opcion;
    int opcionQueue;
    int identificadorGente=1;
    do{
        printf("Que desea hacer: \n");
        printf("   (1) QUEUE\n");
        printf("   (2) DEQUEUE\n");
        printf("   (3) Mostrar la fila completa\n");
        printf("   (0) Salir del programa\n");
        scanf(" %i",&opcion);

        if(opcion==1){
            do {
                Limpiar_Pantalla;
                printf("Ingrese la prioridad del cliente\n");
                printf("   (1) Alta\n");
                printf("   (2) Baja\n");
                scanf(" %i",&opcionQueue);
            }while(opcionQueue!=1 && opcionQueue!=2);

            if(opcionQueue==1){
                QUEUE_P(identificadorGente);
                identificadorGente++;
            }
            else{
                QUEUE(identificadorGente);
                identificadorGente++;
            }
            Limpiar_Pantalla;
        }
        if(opcion==2){
            Limpiar_Pantalla;
            DEQUEUE();
        }
        if(opcion==3){
            Limpiar_Pantalla;
            mostrarLista(first);
        }
    }while(opcion!=0);
}

void QUEUE_P(int n){ //---LISTO
    node* ptrnew = (node*)malloc(sizeof(node));
    ptrnew->n = n;
    ptrnew->next = NULL;
    if (first == NULL) { //si lista vacia LISTO
        first = ptrnew;
        first->cambio=-1;
    }
    else{ //si no esta vacia
        node* tmp = first;
        while(1>0){
            if(tmp->cambio==1){ //si no hay de alta prioridad LISTO
                ptrnew->next=tmp;
                first=ptrnew;
                ptrnew->cambio=-1;
                break;
            }
            if(tmp->next == NULL){ //si no hay de baja prioridad LISTO
                tmp->next=ptrnew;
                tmp->cambio=0;
                ptrnew->cambio=-1;
                break;
            }
            if( (tmp->cambio==-1) && (tmp->next!=NULL) ){ //si hay de baja y alta prioridad LISTO
                ptrnew->next=tmp->next;
                tmp->cambio=0;
                ptrnew->cambio=-1;
                tmp->next=ptrnew;
                break;
            }

            if(tmp->next != NULL){
                tmp = tmp->next;
            }
        }
    }
}

void QUEUE(int n) { //---LISTO
    node* ptrnew = (node*)malloc(sizeof(node));
    ptrnew->n = n;
    ptrnew->next = NULL;
    if (first == NULL) { //si lista esta vacia LISTO
        first = ptrnew;
        ptrnew->cambio=1;
    }
    else{ //lista no vacia
        node* tmp = first;

        while(1>0){
            if(tmp->next == NULL){ //LISTO
                if(tmp->cambio==-1){ //si no habia otro de baja prioridad LISTO
                    tmp->next=ptrnew;
                    ptrnew->cambio=1;
                }
                else{ //dpues de un baja prioridad
                    tmp->next=ptrnew;
                }
                break;
            }
            if(tmp->next != NULL){ //LISTO
                tmp = tmp->next;
            }
        }
    }
}

void DEQUEUE() {
    if (first != NULL) {
        int n;
        node* tmp = first;
        first = tmp->next;
        n = tmp->n;
        free(tmp);
        printf("%i atendido\n",n);
    }
    else{
        printf("lista vacia, no se puede atender\n");
    }
}

void mostrarLista(node* first)
{
    // Recorriendo la lista
    printf("\nLista: ");
    node* ptr = first;
    while (ptr != NULL)
    {
        printf("%i ", ptr->n);
        ptr = ptr->next;
    }
    printf("\n\n");
}
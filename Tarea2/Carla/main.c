#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next; //puntero al proximo nodo de la lista
    struct Node *prev; //puntero al nodo anterior de la lista
};

void contenido1(struct Node *node);
void contenido2(struct Node *node);
void cantidad(struct Node *node);
void borrar(struct Node **head_ref, int posicion);
void agregar(struct Node **head_ref, int nuevoElemento);
void menu();

struct Node* head = NULL; //crea una cabeza para una lista vacia

int main()
{
  menu();
}

void contenido1(struct Node *node){ //Esta funcion imprime el contenido de la lista
    struct Node *aux;
    printf("Elementos de la lista de izquierda a derecha:\n");
      if(node != NULL){
        while(node != NULL){
          printf(" %d ", node->data);
          aux = node;
          node = node->next;
        }
      }
      else{
      printf("No hay elementos en la lista\n");
      }
    printf("\n");
}
void contenido2(struct Node *node){
  
  struct Node *current = node;
  printf("Elementos de la lista de derecha a izquierda:\n");
  if(current==NULL){ 
    printf("No hay elementos en la lista\n");
    return;
  }
  while(current->next != NULL) 
    {
      current = current->next; 
    }
  while(current != NULL)
    {
      printf(" %d ", current->data);
      current = current->prev; 
    }
  printf("\n");
}


void cantidad(struct Node *node){
 
    struct Node *auxiliar; //Lo usamos para recorrer la lista
    if (node == NULL){
        printf("No hay elementos en la lista\n");
    }
    else{
        int contador;
        contador=0;
        while (node != NULL){
        auxiliar = node;
        node = node->next;
        contador++;
        }
        printf("Existen %i elementos en la lista\n", contador);
    }
}
void borrar(struct Node **head_ref, int posicion){
    //head_ref --> puntador al puntador cabeza.
    
    if (*head_ref == NULL){ //Si la lista está nula
        return;
    }
    
    struct Node* temp = *head_ref; //Mantener el node cabeza 

    if (posicion == 0){  //Si la cabeza necesita ser borrada 
        *head_ref = temp->next;   //Cambiar la cabeza
        free(temp);               //Liberar la cabeza anterior
        return;
    }
 
    for (int i=0; temp!=NULL && i<posicion-1; i++){ //Encontrar el nodo previo al nodo que se va a borrar
        temp = temp->next; 
    }
        
 
    if (temp == NULL || temp->next == NULL){ //Si la posicion es mas que el numero de nodos
        return;
    } 

    struct Node *next = temp->next->next;   //Nodo temp->next es el nodo a borrar
                                            //Guardar puntador para el próximo del nodo que se borrará
    free(temp->next);
    temp->next = next;  
}  
void agregar(struct Node** head, int nuevoElemento)

{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head; 
 
    new_node->data  = nuevoElemento;
 
    new_node->next = NULL;
 
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
 
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
    return;
}
void menu(){
  //menu
  int respuesta;
  do{
    printf("Seleccione su opción\n");
    printf("1. Informar la cantidad de elementos en la lista\n"); 
    printf("2. Mostrar el contenido de todos los elementos de la lista\n"); 
    printf("3. Agregar un nuevo elemento\n"); 
    printf("4. Borrar un elemento\n");
    printf("5. Evacuar\n");
    
    scanf("%i", &respuesta);

    switch(respuesta) {
        case 1:
            printf("La cantidad de elementos en la lista es: \n"); 
            cantidad(head);
            break;
        case 2:
            printf("Deseas ver los elementos de la lista de 1. izquierda a derecha o de 2. derecha a izquierda?\n");
            int direccion;
            scanf("%i", &direccion);
            if(direccion==1){
              contenido1(head);
            }
            else{
              contenido2(head);
            }
            break;
        case 3:
            printf("Qué elemento quieres agregar? :\n");
            int nuevoElemento;
            scanf("%i", &nuevoElemento);
            agregar(&head, nuevoElemento); 
            break;
        case 4:
            printf("Qué elemento de la lista quieres borrar? Ingrese en que lugar de la lista se encuentra 1, 2, 3, etc:\n");
            contenido1(head);
            int borrarElemento;
            scanf("%i", &borrarElemento);
            borrar(&head, borrarElemento-1);
            break;
        case 5:
            break;
        default:
            printf("No escogiste ninguna opción válida\n");
            break;
    }
  }while (respuesta!=5);
}
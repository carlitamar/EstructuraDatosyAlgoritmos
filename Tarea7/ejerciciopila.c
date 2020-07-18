// Hecho por Juan Francisco Ternicien
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int n;
    struct node* next;
}node;

void push(int numero,node** estacionamiento);
void pop(node** estacionamiento);
int peek(node* head);
int isempty(node* head);
void aparcarAuto(node ** estacionamiento1,node ** estacionamiento2);
int contarPila(node* head);
void swap(node* n1, node* n2);
void ordenaPila(node ** estacionamiento);
void imprimirPila(node ** estacionamiento);
void dormir(node ** estacionamiento1, node ** estacionamiento2);


int main(){
	
	node * estacionamiento1 = NULL;
	node * estacionamiento2 = NULL;
	int opcion;

	do
    {
        //imprimir instrucciones
        printf("\nMENU\n\n"
               "1 - Aparcar un Auto\n"
               "2 - Dormir\n"
               "3 - Mostrar estacionamientos \n"
               "0 - Salir\n\n");
        
        // obtener una opción
        printf("Elija una opción: ");
        scanf("%d",&opcion);
        
        // Ejecutar la opción
        switch (opcion)
        {
            case 1: aparcarAuto(&estacionamiento1,&estacionamiento2); break;
            case 2: dormir(&estacionamiento1,&estacionamiento2); break;
            case 3: 
            printf("\n");
            printf("Espacios disponibles del primer estacionamiento\n");
            imprimirPila(&estacionamiento1);
            printf("\n\n");
            printf("Espacios disponibles del segundo estacionamiento\n");
            imprimirPila(&estacionamiento2);
            printf("\n");
            break;
        }
    }
    while (opcion != 0);
	return 0;
}





void aparcarAuto(node ** estacionamiento1,node ** estacionamiento2){
	int numero;
	node * est1 = *estacionamiento1;
	node * est2 = *estacionamiento2;
	int cupos1 = contarPila(est1);
	int cupos2 = contarPila(est2); /// COPIAS POR SI ACA

	if (cupos1 == 6 && cupos2 == 6){
		printf("\n");
		printf("No quedan cupos \n");
		return;
	}
	

	printf("Ingresa las horas que estara aparcado el movil\n");
	scanf("%i",&numero);

	if(*estacionamiento1 == NULL){
		push(numero,estacionamiento1);
		return;
	}

	if (cupos1 < 6){
		push(numero,estacionamiento1);
		ordenaPila(estacionamiento1);
	}

	if (cupos1 == 6  && cupos2 < 6)
	{
		int arreglo[7];
		int contador=0;

		push(numero,estacionamiento1);
		ordenaPila(estacionamiento1);

		while((*estacionamiento1)->next != NULL){
			arreglo[contador]= (*estacionamiento1)->n;
			pop(estacionamiento1);
			contador++;
		}
		push((*estacionamiento1)->n,estacionamiento2);
		ordenaPila(estacionamiento2);
		pop(estacionamiento1);

		for (int i = contador-1; i >= 0; i--)
		{
			push(arreglo[i],estacionamiento1);
		}
	
	}

}

void ordenaPila(node ** estacionamiento){
	node* temp = *estacionamiento;
	while(temp->next != NULL && temp->n > temp->next->n){
		swap(temp, temp->next);
		temp = temp->next;
	}

}


int contarPila(node* head){
	node * temp = head;
	int contador = 0;
	while(temp != NULL){
		temp = temp->next;
		contador++;
	}
	return contador;
}


//agregar elemento
void push(int numero, node** estacionamiento)
{
    //crea un nuevo nodo vacio
    node* newptr = (node*) malloc(sizeof(node));

    //inicialización del nodo
    newptr->n = numero;
    newptr->next = NULL;

    //Verificando si la lista esta vacia
    if (*estacionamiento == NULL)
    {
        *estacionamiento = newptr;
    }
        //insertar al inicio
    else
    {
        newptr->next = *estacionamiento;
        *estacionamiento = newptr;
    }
}

//quitar elemento
void pop(node** estacionamiento)
{	
	node* temp= *estacionamiento;
        if(temp!=NULL) //si existe una pila
        {
            if(temp->next!=NULL){ //si sigue existiendo una pila
                *estacionamiento=temp->next;
            }
            else{ //si pila queda vacia
                *estacionamiento=NULL;
            }
            free(temp);
        }
        else{
        printf("Pila vacia (desde pop)\n");
    }
}

//Mirar el inicial
int peek(node* head)
{
    node* ptr = head;
    if(ptr != NULL)
    {
        return ptr->n;
    }
    else{
        printf("Pila vacia (desde peek)\n");
        return 0;
    }

    printf("\n\n");
}


int isempty(node* head){
    if(head != NULL) //si no esta vacia
    {
        return 0;
    }
    else{ //si esta vacia
        return 1;
    }
}
void swap(node * n1,node * n2){
	int temp = n1->n;
	n1->n = n2->n;
	n2->n = temp;

}
void imprimirPila(node ** estacionamiento){
	int cupos = 6-contarPila(*estacionamiento);
	node * temp = *estacionamiento;

	while(temp != NULL){
	printf("//OCUPADO// --tiempo restante: %i horas\n", peek(temp) );
	temp = temp->next;
	}
	for (int i = 0; i < cupos; ++i)
	{
		printf("//DISPONIBLE//\n");
	}

}
void dormir(node ** estacionamiento1, node ** estacionamiento2){
	
	int cupos1 = contarPila(*estacionamiento1);
	int cupos2 = contarPila(*estacionamiento2); /// COPIAS POR SI ACA
	int dormir;
	node * temp = *estacionamiento1;
	node * temp2 = *estacionamiento2;
	int arreglo[7];
	int contador=0;
	int eliminados1 = 0;
	int eliminados2 = 0;

	printf("Ingrese tiempo por dormir: \n");
	scanf("%i",&dormir);

	for (int i = 0; i < cupos1; i++)
	{
		if (temp->n <= dormir)
		{
			printf("DEBUGIN\n");
			pop(estacionamiento1);
			temp = temp->next;
			eliminados1++;
		}
		
	}
	while((*estacionamiento1) != NULL){
			arreglo[contador]= (*estacionamiento1)->n;
			pop(estacionamiento1);
			contador++;
	}
	for (int i = contador-1; i >= 0; i--)
	{
			push(arreglo[i]-dormir,estacionamiento1);
	}
	contador = 0;

	for (int i = 0; i < cupos2; i++)
	{
		if (temp2->n <= dormir)
		{
			pop(estacionamiento2);
			temp2 = temp2->next;
			eliminados2++;
		}
		
	}
	while((*estacionamiento2) != NULL){
			arreglo[contador]= (*estacionamiento2)->n;
			pop(estacionamiento2);
			contador++;
	}
	for (int i = contador-1; i >= 0; i--)
	{
			push(arreglo[i]-dormir,estacionamiento2);
	}

	int demanda = eliminados1;
	int disponible = cupos2 - eliminados2;

	if (demanda > disponible)
	{
		for (int i = 0; i < disponible; ++i)
		{
			push(peek(*estacionamiento2),estacionamiento1);
			pop(estacionamiento2);
			ordenaPila(estacionamiento1);
		}
	}
	else{
		for (int i = 0; i < demanda; ++i)
		{
			push(peek(*estacionamiento2),estacionamiento1);
			pop(estacionamiento2);
			ordenaPila(estacionamiento1);
		}
	}
}
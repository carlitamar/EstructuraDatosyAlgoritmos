// Hecho por Juan Francisco Ternicien
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo* delante;
	struct nodo* detras;


}nodo;

typedef nodo* ptrN;

void anadirElemento(int x);
void displayMenu();
int elementosEnLista();
ptrN crearNodo(int);
void actualizarHead();
void imprimirEnFormaDePiramide();
void enmontanar();
void swap();
void mostrarLista();


ptrN HEAD = NULL; // Se crea la lista

int main(){

	int x;
	printf("Ingrese un valor para el nodo\n");
	scanf("%i",&x);
	while(x != -1){
		anadirElemento(x);
		printf("Ingrese un valor para el nodo\n");
		scanf("%i",&x);
	}

	enmontanar();
	mostrarLista();
	printf("Ahora en forma de montana =)\n\n");
	imprimirEnFormaDePiramide();
	return 0;
}

// anade elemento de manera ordenada
void anadirElemento(int x){
	ptrN aux = HEAD;

	int bolean = 0;
	int valor = x;

	ptrN nodoNuevo= crearNodo(valor);



	if (HEAD == NULL){
		HEAD = nodoNuevo;
		bolean = 1;
		return;
	}


	if (nodoNuevo->valor >= aux->valor)
	{
		if (aux->delante == NULL)
		{
			nodoNuevo->delante = NULL;
			nodoNuevo->detras = aux;

			aux->delante = nodoNuevo;

			bolean =1;
			
		}

		while(aux->delante != NULL && bolean != 1){

			aux = aux->delante;

			if(nodoNuevo->valor <= aux->valor){
				nodoNuevo->delante = aux;
				nodoNuevo->detras = aux->detras;
				aux->detras->delante = nodoNuevo;
				aux->detras = nodoNuevo;
				bolean = 1;
			}
		}
		if (bolean == 0)
		{
			nodoNuevo->delante = NULL;
			nodoNuevo->detras = aux;
			aux->delante=nodoNuevo;
			bolean = 0;	
		}
		actualizarHead();

	}
	else{
		if (aux->detras == NULL)
		{
			nodoNuevo->detras = NULL;
			nodoNuevo->delante = aux;

			aux->detras = nodoNuevo;

			bolean = 1;
			
		}

		while(aux->detras != NULL && bolean != 1){

			aux = aux->detras;

			if(nodoNuevo->valor >= aux->valor){
				nodoNuevo->delante = aux->delante;
				nodoNuevo->detras = aux;
				aux->delante->detras = nodoNuevo;
				aux->delante = nodoNuevo;
				bolean = 1;
			}
		}
		if (bolean == 0)
		{
			nodoNuevo->detras = NULL;
			nodoNuevo->delante = aux;
			aux->detras=nodoNuevo;
			bolean = 0;	
		}
		actualizarHead();

	}

}


int elementosEnLista(){
	ptrN aux = HEAD;
	ptrN aux2 = HEAD;
	int contador = 0;

	while(aux != NULL){
		contador++;
		aux = aux->delante;
	}
	while(aux2 != NULL){
		contador++;
		aux2 = aux2->detras;
	}
	return contador-1;
}

ptrN crearNodo(int n){
	ptrN newptr = (ptrN) malloc(sizeof(nodo));
    newptr->valor = n;
    newptr->delante = NULL;
    newptr->detras = NULL;


    return newptr;
}
void actualizarHead(){
	ptrN aux = HEAD;

	int elementos = elementosEnLista();
	int mitad;


	while(aux->detras != NULL){
		aux = aux->detras;
	}
	if (elementos % 2 == 1)
	{
		mitad = (elementos+1)/2;
	}
	else{
		mitad = elementos/2;
	}
	for (int i = 0; i < mitad-1; ++i)
	{
		aux= aux->delante;
	}
	
	HEAD =aux;

}
void imprimirEnFormaDePiramide(){
	ptrN aux = HEAD;
	ptrN aux2 = HEAD;
	int largo = elementosEnLista();

	
	if (largo % 2 ==1)
	{
		for (int i = 0; i < (largo+1)/2; i++)
		{
			for (int j = largo; j > 0; j--)
			{
				
				if (i==j)
				{
					aux = aux->detras;

					printf("%i",aux->valor);
				}
				else{
					printf(" ");
				}
			}


			for (int j = 0; j < largo; j++)
			{
				if (i==j)
				{
					printf("%i",aux2->valor);
					aux2 = aux2->delante;
				}
				else{
					printf(" ");
				}
			}

			printf("\n");
		}
	}
	else
	{
		for (int i = 0; i < (largo+2)/2; i++)
		{
			for (int j = (largo+1)/2-1; j > 0; j--)
			{
				
				if (i==j)
				{
					aux = aux->detras;

					printf("%i",aux->valor);
				}
				else{
					printf(" ");
				}
			}


			for (int j = 0; j < largo; j++)
			{
				if (i==j)
				{
					printf("%i",aux2->valor);
					aux2 = aux2->delante;
				}
				else{
					printf(" ");
				}
			}

			printf("\n");
		}
	}
	
}


void mostrarLista(){

	ptrN aux = HEAD;
	if (aux == NULL){ printf("Tu lista se encuentra vacia\n"); return;}
	char sentido = '1';
	
	if(sentido == '1'){
		printf("Tu lista es: \n");

		printf("NULL - ");
		while(aux->detras != NULL){
			aux = aux->detras;

		}
		while(aux != NULL){
			printf("%d - ",aux->valor);
			aux = aux->delante;
		}
		printf("NULL");


	}
	printf("\n");
	
}
void enmontanar (){
	ptrN aux = HEAD;
	ptrN aux2 = HEAD;
	int contador =1;

	if(elementosEnLista() <=2){return;}

	while(aux2->delante != NULL){
		aux2 = aux2->delante;
		contador++;
	}
	if (elementosEnLista() == 3)
	{
		swap(aux,aux2);
		return;
	}
	if (contador % 2 == 1)
	{
		aux = aux->delante;
		swap(aux,aux2);
		while(aux->delante != aux2){
			aux = aux->delante;
			aux2 = aux2->detras;
			swap(aux,aux2);
		}
	}
	else{
		aux = aux->delante;
		while(aux != aux2){
			swap(aux,aux2);
			aux = aux->delante;
			aux2 = aux2->detras;
		}
	}



}
void swap(ptrN n1, ptrN n2){
	int temp = n1->valor;
	n1->valor = n2->valor;
	n2->valor = temp;

}
void clean_stdin(void)
{
	int c;
	do{
		c = getchar();
	} while(c != '\n' && c != EOF);

}
